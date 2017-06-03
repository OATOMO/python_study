/*
 *ROI(Region Of Interest)
 * */

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc,char ** argv){
	/*cv::Mat image(200,100,CV_8U,cv::Scalar(100));
	cout << "image.cols -> " << image.cols 
		 << "image.rows -> " << image.rows << endl;
	
	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::waitKey(0);

	image.create(cv::Size(200,100),CV_8U);
	cv::imshow("Image",image);
	cv::waitKey(0);
	*/
	cv::Mat image;
	image = cv::imread("/home/atom/Desktop/tu.jpeg");

	cv::Mat logo;
	logo = cv::imread("/home/atom/Desktop/OATOMO.png");

	cv::Mat mask(logo);

	cv::Mat imageROI(image,
					cv::Rect(image.cols-logo.cols,0,
					logo.cols,logo.rows));
	

	//cv::Mat imageROI = image.rowRange(0,logo.rows);


	logo.copyTo(imageROI);

	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::waitKey(0);

return 0;
}
