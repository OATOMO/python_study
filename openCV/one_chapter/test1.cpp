#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <iostream>

using std::cout;
using std::endl;

void onMouse(int event,int x,int y,int flags,void *param);

int main(int argc,char ** argv){
	if(argc <= 1){
		cout << "usage : " << endl;
		cout << "	__name__  <iamgePath>";
		return -1;
	}
	cv::Mat image;//创建一个空图像,这个定义创建的是0x0的图像
	cout << "This Image is" << image.rows << "x" 
		 << image.cols << endl;

	image = cv::imread(argv[1]); //读入输入的图片
	image = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE); //灰度读取
	//image = cv::imread(argv[1],CV_LOAD_IMAGE_COLOR); //3通道读取-3btyes
	if(image.empty()){
		cout << "读入错误" << endl;
		return -1;
	}	
	//加载后显示图像
	cout << "加载后" << endl;
	cout << "This Image is" << image.rows << "x" 
		 << image.cols << endl;

	cout << "This Image has "
		 << image.channels() << " changles"
		 << endl; //channels()方法检查通道数 


	//下面这两个函数用名字来匹配
	cv::namedWindow("Original Image");  //定义窗口
	cv::imshow("Original Image",image);		//显示图片

	cv::waitKey(0);//0表示永久等待按键，正数表示等待毫秒数
	
	cv::flip(image,image,1);//正数表示水平，0表示垂直，负数表示水平垂直
	cv::imshow("Original Image",image);		//显示图片

	cv::setMouseCallback("Original Image",onMouse,
					reinterpret_cast<void*>(&image));//注册mouse回调函数

	cv::waitKey(0);//0表示永久等待按键，正数表示等待毫秒数
	

return 0;
}

void onMouse(int event,int x,int y,int flags,void *param){
		cv::Mat * pImage = reinterpret_cast<cv::Mat*>(param);
		switch (event){  //调度事件
				case CV_EVENT_LBUTTONDOWN:  //鼠标左键按下
					//显示像素值
					cout << "at (" << x << "," << y << ") value is:"
						 << static_cast<int>(
						pImage->at<uchar>(cv::Point(x,y))) << endl;
				break;
				case CV_EVENT_RBUTTONDOWN:  //鼠标左键按下
					cv::circle(*pImage,			//目标图像
							   cv::Point(x,y), 	//中心点坐标
							   60,				//半径
						   	   0,				//颜色
						  	   3);				//厚度

					cv::putText	(*pImage,"This is a Text!",
								cv::Point(x,y+70),  		//文本位置
								cv::FONT_HERSHEY_PLAIN,	//字体类型
								2.0,					//字体大小
								255,					//颜色
								2);						//文本厚度
					cout << "(" << x << "," << y << ")" <<endl; 
					cv::imshow("Original Image",*pImage);		//显示图片
				break;
		}
}






