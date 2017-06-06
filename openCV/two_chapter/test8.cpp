/*
 c[i] = a[i]+b[i];
 cv::add(imageA,imageB);

 c[i] = a[i] + K;
 cv::add(imageA,cv::Scalar(k),resultC);

 c[i] = k1*a[1] + k2*a[2] + k3
 cv::addWeighted(imageA,k1,imageB,k2,k3,resultC);
 * */
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

int main(){
	cv::Mat image1 = cv::imread("/home/atom/Desktop/5.jpg");
	cv::Mat image2 = cv::imread("/home/atom/Desktop/tu.jpeg");
	cv::Mat ROI(image1,cv::Rect(0,0,image2.cols,image2.rows));


	cv::Mat result;
	cv::namedWindow("Image");

	std::cout << image2.channels() << std::endl;
	cv::imshow("Image",image1);

	cv::waitKey();

	cv::addWeighted(ROI,0.9,image2,0.1,0.0,ROI);
	cv::imshow("Image",image1);

	cv::waitKey();
return 0;
}
