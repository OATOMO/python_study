/*
 *	测试opencv自带的通道转与自己写的
 *	处理速度的区别
 *	***************result
 *	opencv func  pro time = 0.040276 s
 *	may func  pro time = 0.032938 s
 *
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

void RGBtoGray( Mat &src,Mat &des){
	//(R*30 + G*59 + B*11 + 50)/100;
	des.create(src.rows,src.cols,CV_8UC1);
	for (int r = 0;r < src.rows;r++){
		for(int c = 0;c < src.cols;c++){
			Vec3b * pSrc = src.ptr<cv::Vec3b>(r,c);
			uchar *   pDes = des.ptr<uchar>(r,c);
			int gray = (pSrc->val[0]*11 + 
						pSrc->val[1]*59 + 
						pSrc->val[2]*30 + 50)/100;	
			*pDes = gray;
		}
	}
}

int main(){
	Mat src = imread("/home/atom/Desktop/tu.jpeg");
	Mat cv_des;
	Mat my_des;
	
	proTime();
	cvtColor(src,cv_des,COLOR_BGR2GRAY);
	proTime("opencv func ");

	proTime();
	RGBtoGray(src,my_des);
	proTime("may func ");

	imshow("mydes",my_des);
	imshow("opencv des",cv_des);

	waitKey();
}


