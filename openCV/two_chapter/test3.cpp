/*
 *迭代器扫描图片
 *
 *
 *
 * */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>


void colorReduce(cv::Mat &image,int div = 64){
/*俩种方法定义迭代器
 * 定义时就得指定类型
 * cv::MatIterator_<cv::Vec3b> it;
 */
	cv::Mat_<cv::Vec3b>::iterator it = 
				image.begin<cv::Vec3b>();

	cv::Mat_<cv::Vec3b>::iterator itend = 
				image.end<cv::Vec3b>();
	for (;it != itend;++it){
		//处理像素
		(*it)[0] = (*it)[0]/div * div + div>>1;	
		(*it)[1] = (*it)[1]/div * div + div>>1;	
		(*it)[2] = (*it)[2]/div * div + div>>1;	
	}

}

int main(int argc,char ** argv){
	cv::Mat image = cv::imread("/home/atom/Desktop/tu.jpeg");
	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::waitKey(0);
	
	const int64 start = cv::getTickCount();
	colorReduce(image);
	double duration = (cv::getTickCount() - start)/cv::getTickFrequency();
	//see 效率
	std::cout << "proccess " << duration << "s" << std::endl;

	cv::imshow("Image",image);
	cv::waitKey(0);
return 0;
}

