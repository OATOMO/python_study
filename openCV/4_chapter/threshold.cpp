/*
 * threshold
 * */
#include <sys/types.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

void proTime(const char * text = ""){
	static bool flag = false;
	static long long start =0;
	double duration;
	if(flag == false){
		start = cv::getTickCount();
		flag = true;
		return ;	
	}
	duration = (cv::getTickCount()-start)/cv::getTickFrequency();
	flag = false;
	printf("%s pro time = %1.5g s\n",text,duration);	
}


int main(){
	Mat src = imread("/home/atom/Desktop/tu.jpeg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat bin;
	//二进制阈值化
	proTime();
	threshold(src,bin,100,255,cv::THRESH_BINARY);
	proTime("threshold ");

	imshow("src",src);
	imshow("bin",bin);
	waitKey();

	proTime();
	threshold(src,bin,100,255,cv::THRESH_BINARY_INV);
	proTime("threshold inv ");

	imshow("src",src);
	imshow("bin",bin);
	waitKey();


}
