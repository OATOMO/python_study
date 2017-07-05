/*
 * g(i,j) = a*f(i,j) + b
 * a(1.0~3.0)对比度  b(0~100)亮度
 * saturate_cast<uchar> 防止溢出
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

void changeGain(Mat &src,Mat &des,float a,int b){
/* g(i,j) = a*f(i,j) + b
 * a(1.0~3.0)对比度  b(0~100)亮度
 * saturate_cast<uchar> 防止溢出
 * */
	des.create(src.rows,src.cols,CV_8UC3);
	for (int r = 0;r < src.rows;r++){
		for (int c = 0;c < src.cols;c++){
			Vec3b *p = src.ptr<Vec3b>(r,c);
			Vec3b *d = des.ptr<Vec3b>(r,c);
			d->val[0] =saturate_cast<uchar>(p->val[0]*a + b);
			d->val[1] =saturate_cast<uchar>(p->val[1]*a + b);
			d->val[2] =saturate_cast<uchar>(p->val[2]*a + b);
		}
	}
			
}

int main(){
	Mat src = imread("/home/atom/Desktop/tu.jpeg");
	Mat my_gain;
	Mat cv_gain;
	proTime();
	changeGain(src,my_gain,2.0,50);
	proTime("may Gain ");

	imshow("src",src);
	imshow("my_gain",my_gain);
	waitKey();

	proTime();
	src.convertTo(cv_gain,-1,2.0,50);
	proTime("cv Gain ");
	imshow("cv_gain",my_gain);
return 0;
}
