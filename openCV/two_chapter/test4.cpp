/*
 *sharpen 锐化
 * */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

void sharpen(const cv::Mat &image, cv::Mat &result){
	//判断是否需要分配图像数据.如果需要就分配
	result.create(image.size(),image.type());
	int nchannels = image.channels();//获得通道数
	//不处理frist行和last行
	for (int j = 1;j < image.rows-1;j++){
		const uchar * previous = image.ptr<uchar>(j-1); //上一行
		const uchar * current = image.ptr<uchar>(j);	//当前行
		const uchar * next = image.ptr<uchar>(j+1);		//下一行
		uchar * output = result.ptr<uchar>(j);	
		for (int i = nchannels; i < (image.rows-1)*nchannels;i++ ){
			//saturate_cast饱和函数,把大小限制在类型以内
			*output++ = cv::saturate_cast<uchar>(
					5*current[i] - current[i-nchannels] - 
					current[i+nchannels] - previous[i] - 
					next[i]);
		}
	}

	//未处理的设为0
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows-1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols-1).setTo(cv::Scalar(0));

}

int main(int argc,char ** argv){
	cv::Mat image = cv::imread("/home/atom/Desktop/tu.jpeg"/*,CV_LOAD_IMAGE_GRAYSCALE*/);
	cv::Mat result;
	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::waitKey(0);

	const int64 start = cv::getTickCount();
	sharpen(image,result);
	double duration = (cv::getTickCount() - start)/cv::getTickFrequency();
	//see 效率
	std::cout << "proccess " << duration << "s" << std::endl;
	
	cv::imshow("Image",result);
	cv::waitKey(0);


return 0;
}
