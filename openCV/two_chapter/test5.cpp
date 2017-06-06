/*
 *鉴于滤波是图像处理中常见的操作，opencv专门为此定义了一个
 *函数，cv::filter2D(),要使用这个函数只需要定义一个内核（以矩阵的形式）
 *调用并传入图像和内核，即可返回滤波后的图像
 * */

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

void sharpen2D(const cv::Mat &image,cv::Mat &result){
	//构造内核（所有入口都初始化为0）
	cv::Mat kernel(3,3,CV_32F,cv::Scalar(0));
	//对内核赋值
	kernel.at<float>(1,1) = 5.0;
	kernel.at<float>(0,1) = -1.0;
	kernel.at<float>(2,1) = -1.0;
	kernel.at<float>(1,0) = -1.0;
	kernel.at<float>(1,2) = -1.0;
	
	//对图片滤波
	cv::filter2D(image,result,image.depth(),kernel);
}


int main(int argc,char ** argv){
	cv::Mat image = cv::imread("/home/atom/Desktop/tu.jpeg"/*,CV_LOAD_IMAGE_GRAYSCALE*/);
	cv::Mat result;
	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::waitKey(0);

	const int64 start = cv::getTickCount();
	sharpen2D(image,result);
	double duration = (cv::getTickCount() - start)/cv::getTickFrequency();
	//see 效率
	std::cout << "proccess " << duration << "s" << std::endl;
	
	cv::imshow("Image",result);
	cv::waitKey(0);


return 0;
}
