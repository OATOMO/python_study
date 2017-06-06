#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void draw_ellipse(Mat image,double angle,Point point){
	
	ellipse(image,point,Size(100,30),angle,0,360,Scalar(0,0,100),1,18);
}

int main(){
	Mat background(400,400,CV_8U,Scalar(100));
	namedWindow("Image");
	imshow("Image",background);
	waitKey();

	Point point = Point(200,200);

	for (double i = 0;i <= 360.0-45.0;i+= 45.0){
		draw_ellipse(background,i,point);
	}
	circle(background,point,10,Scalar(0,0,100),-1,8);

	imshow("Image",background);
	waitKey();

return 0;
}
