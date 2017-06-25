/*
 *	(ROI)Region Of Interest
 *	cv::Rect rect(100,100,200,200);
 *				   x,  y, w,  h
 * */
#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
	cv::Mat image = cv::imread("/home/atom/Desktop/tu.jpeg");
	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::waitKey();

	cv::Rect rect(0,0,200,100);
	cv::Mat rect_mat = image(rect);
	for (int row = 0;row < rect_mat.rows;row++){
		for(int col = 0;col < rect_mat.cols;col++){
			cv::Vec3b *p  = rect_mat.ptr<cv::Vec3b>(row,col); 
			p->val[0] = 255;
			p->val[1] = 255;
			p->val[2] = 255;
		}
	}	
	cv::imshow("rect",rect_mat);
	cv::imshow("Image",image);
	cv::waitKey();

return 0;
}
