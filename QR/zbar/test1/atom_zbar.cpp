#include <iostream>
#include <string>
#include "zbar.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace zbar;

void onMouse(int event,int x,int y,int flags,void *param);

int main(int argc,char ** argv){
	if(argc <= 1){
		cout << "user: " << argv[0] << " [image]" << endl;
		return -1;
	}
	//string filename = argv[1];
	cv::Mat image_src = cv::imread(argv[1]);
	cv::Mat image;
	image_src.copyTo(image);

	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::setMouseCallback("Image",onMouse,reinterpret_cast<void *>(&image));//注册鼠标回调函数
	cv::waitKey();

	//二值化
	cv::threshold(image,image,100, 	//临界值
					255,			//最大值
					CV_THRESH_BINARY);//模式   
	cv::imshow("Image",image);
	cv::waitKey();


return 0;
}



void onMouse(int event,int x,int y,int flags,void *param){
	cv::Mat * pImage = reinterpret_cast<cv::Mat *>(param);
	switch(event){
		case CV_EVENT_LBUTTONDOWN://左键按下
		cout << "at (" << x << "," << y <<") value is:"
			 << static_cast<int>(pImage->at<uchar>(cv::Point(x,y))) << endl;
		break;
	}

}
