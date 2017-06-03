/*
 *salt and pepper noise
 * */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

void see_rows(cv::Mat image);
void salt(cv::Mat ,int n);

int main(int argc,char ** argv){
	cv::Mat image;
	image = cv::imread("/home/atom/Desktop/tu.jpeg");
	cv::namedWindow("Image");
	cv::imshow("Image",image);
	
	cv::waitKey(0);

	salt(image,1000);
	cv::imshow("Image",image);
	
	cv::waitKey(0);

	see_rows(image);
	cv::imshow("Image",image);
	
	cv::waitKey(0);


return 0;
}

void salt(cv::Mat image,int n){
	int i,j;
	for (int k; k < n;k++){
		i = std::rand()%image.cols;	//x
		j = std::rand()%image.rows;	//y
		if(image.type() == CV_8UC1){	//gray
			image.at<uchar>(j,i) = 255;
		}

		else if(image.type() == CV_8UC3){
			image.at<cv::Vec3b>(j,i)[0] =255;
			image.at<cv::Vec3b>(j,i)[1] =255;
			image.at<cv::Vec3b>(j,i)[2] =255;
		}	//color
	}
}

void see_rows(cv::Mat image){
	int c = 200;
	for (int i = 0;i < c;i++){
		if(image.type() == CV_8UC1){	//gray
			image.at<uchar>(0,i) = 255;
		}

		else if(image.type() == CV_8UC3){
			image.at<cv::Vec3b>(0,i)[0] =100;
			image.at<cv::Vec3b>(0,i)[1] =100;
			image.at<cv::Vec3b>(0,i)[2] =100;
		}	//color
		
		
	}
}
