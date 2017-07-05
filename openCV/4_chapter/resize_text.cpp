/*
 * 比较近邻算法与双线程插值算法的效果与速度
 * result:
 * 双线程插值算法在边缘处不会出现马赛克
 * */
#include <opencv2/opencv.hpp>
#include <iostream>

void my_resize(cv::Mat &src,cv::Mat &des,cv::Size size){
	des.create(size.height,size.width,src.type());
	float dy = (float)src.rows/des.rows;
	float dx = (float)src.cols/des.cols;
	for (int r = 0;r < des.rows;r++){
		int sy = r*dy+0.5;
		for (int c = 0;c < des.cols;c++){
			int sx = c*dx+0.5;
			cv::Vec3b * dp = des.ptr<cv::Vec3b>(r,c);
			cv::Vec3b * sp = src.ptr<cv::Vec3b>(sy,sx);
			dp->val[0] = sp->val[0];
			dp->val[1] = sp->val[1];
			dp->val[2] = sp->val[2];
		}
	}
}

int main(){
		cv::Mat image = cv::imread("/home/atom/Desktop/tu.jpeg");
		cv::Mat my_image_half,my_image_double;
		cv::Mat	cv_image_half,cv_image_double; 
		my_resize(image,my_image_double,cv::Size(image.cols*2,image.rows*2));

		cv::resize(image,cv_image_double,cv::Size(image.cols*2,image.rows*2),CV_INTER_LINEAR);
		cv::imshow("my_image_double",my_image_double);
		cv::imshow("image",image);
		cv::imshow("cv_image_double",cv_image_double);

cv::waitKey();
return 0;
}


