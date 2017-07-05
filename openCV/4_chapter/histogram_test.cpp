/*
 * histogram
 */

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
//创建灰度图像的直方图
class Histogram1D{
private:
	int histSize[1]; //直方图中箱子的数量
	float hranges[2]; //值范围
	const float * range[1]; //值范围的指针
	int channels[1]; //要检查的通道数
public:
	Histogram1D(){
		//默认参数
		histSize[0] = 256; //256个箱子
		hranges[0] = 0.0;  //从0开始(含)
		hranges[1] = 256.0; //到256(不含)
		range[0] = hranges;
		channels[0] = 0;  //先关注通道0
	}

	//用查找表
	static cv::Mat applyLookUp(const cv::Mat &image,
							const cv::Mat &lookup){//uchar 类型的1*256数组
		//输出图像
		cv::Mat result;
		//应用查找表
		cv::LUT(image,lookup,result);
		return result;
	}

	cv::Mat getHistogram(const cv::Mat &image){
		cv::Mat hist;

		//计算直方图
		cv::calcHist(&image,
					1,			//仅为一个图像的直方图
					channels,	//使用的通道
					cv::Mat(),	//不使用掩码
					hist,		//作为结果的直方图
					1,			//这是一个一维的直方图
					histSize,	//箱子数量
					range);		//像素值范围
		return hist;
		}//end  getHistogram();

	cv::Mat getHistogramImage(const cv::Mat &image,int zoom = 1){
		//首先计算直方图
		cv::Mat hist = getHistogram(image);
		//创建直方图
		return 	getImageOfHistogram(hist,zoom);
	}

	static cv::Mat getImageOfHistogram(const cv::Mat &hist,int zoom){
		//取得箱子的最大最小值
		double maxVal = 0;
		double minVal = 0;
		cv::minMaxLoc(hist,&minVal,&maxVal);
		//取得直方图的大小
		int histSize = hist.rows;
		//用于显示直方图的方形图像
		cv::Mat histImg(histSize*zoom,histSize*zoom,CV_8U,cv::Scalar(255));	
		//s设置最高点为90%
		int hpt = static_cast<float>(0.9*histSize);
		//为每个箱子画垂直线
		for (int h = 0; h < histSize; h++) {
			float binVal = hist.at<float>(h);
				if (binVal>0) {
					int intensity = static_cast<int>(binVal*hpt / maxVal);
					cv::line(histImg, cv::Point(h*zoom, histSize*zoom),
							cv::Point(h*zoom, (histSize - intensity)*zoom),
							cv::Scalar(0), zoom);
				}
		}
		return histImg;
	}
};//end Class 

cv::Mat image,proImage;

void on_mouse(int event,int x,int y,int flags,void *ustc){
	static cv::Point pre_pt(-1,-1);	//初始坐标
	static cv::Point cur_pt(-1,-1);	//实时坐标
	if (event == CV_EVENT_LBUTTONDOWN){//点下
		pre_pt = cv::Point(x,y);	
	}
	else if (event == CV_EVENT_MOUSEMOVE && (flags & CV_EVENT_FLAG_LBUTTON)){//拖动
		image.copyTo(proImage);	
		cur_pt = cv::Point(x,y);
		cv::rectangle(proImage,pre_pt,cur_pt,cv::Scalar(0,255,0,0),1,8,0);
		imshow("src",proImage); 
	}
	else if (event == CV_EVENT_LBUTTONUP){//松开
		printf ("point1 = (%d,%d), point2 = (%d,%d)\n",pre_pt.x,pre_pt.y,
						cur_pt.x,cur_pt.y);
		cv::Mat imageROI;
		imageROI = image(cv::Rect(pre_pt.x,pre_pt.y,
						(cur_pt.x-pre_pt.x),(cur_pt.y-pre_pt.y)));	//云彩区域
		Histogram1D h;

		float hranges[2] = {0.0,256.0};
		const float * ranges[1] = {hranges};
		int channels[1] = {0};

		cv::Mat hist=h.getHistogram(imageROI);
		cv::normalize(hist,hist,1.0);
		cv::calcBackProject(&image,
							1,		//1个图像
							channels,		//一个通道
							hist,
							proImage,
							ranges,
							255.0);	
		imshow("src",proImage);
		cv::waitKey();
	}
}

int main(int argc,char ** argv){
	if(argc < 2){
		cout << "user : " << argv[0] << " imageName." << endl;
	}
	image = cv::imread(argv[1],0);	//以黑白方式打开
#if 0
	//直方图对象
	Histogram1D h;
	//计算直方图
	cv::Mat histo = h.getHistogram(image);
	//遍历每个箱子
	for (int i = 0;i < 256;i++){
		cout << "Value " << i << " = " << 
				histo.at<float>(i) << endl;
	}
	//创建查找表
	int dim(256);
	cv::Mat lut(1,&dim,CV_8U);	
	for (int i = 0;i < 256;i++){
		lut.at<uchar>(i) = 255-i;
	}

	image = Histogram1D::applyLookUp(image,lut);
	cv::imshow("lut after",image);
	cv::waitKey();
	
	Histogram1D h;
	cv::imshow("histogram",h.getHistogramImage(image));
	cv::waitKey();
#endif
	cv::namedWindow("src");
	cv::setMouseCallback("src",on_mouse,0);
	cv::imshow("src",image);
	cv::waitKey(0);
return 0;	
}
