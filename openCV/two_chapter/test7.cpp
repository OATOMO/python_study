/*
 用canny进行边缘检测
 * */
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

int main(){
	cv::Mat srcImage = cv::imread("/home/atom/Desktop/3.jpeg");
	cv::namedWindow("Image");
	cv::imshow("Image",srcImage);
	cv::waitKey();

	cv::Mat dstImage,edge,grayImage;

	//创建和src同类型大小的矩阵
	dstImage.create(srcImage.size(),srcImage.type());

	//将原图像转换为gray
	cv::cvtColor(srcImage,grayImage,cv::COLOR_BGR2GRAY);
	//利用3x3的内核来降噪
	cv::blur(grayImage,edge,cv::Size(3,3));
	//运行canny算子
	cv::Canny(edge,edge,3,9,3);
	cv::imshow("Image",edge);
	cv::waitKey();


return 0;
}
