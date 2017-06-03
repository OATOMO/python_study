/*
 *point scan image
 * */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
/*
 *note :
 *uchar *data = image.data;
 *data += image.step; //下一行
 * (j,i)像素的地址,即&image.at(j,i);
 * data = image.data + j*image.step() + i*image.elemSize()
 * */

//color reduce
void colorReduce(cv::Mat image,int div=64){
	if (image.isContinuous()){  //不是连续图片
		image.reshape(1,    	//新的通道数
						1);		//新的行数
	}

	int ny = image.rows; //行数
	int nx = image.cols * image.channels();
	std::cout << "__func__ : proc " << image.total()*image.channels() 
			  << "bytes" << std::endl; 

	for (int j = 0; j < ny; j++){
		uchar * data = 	image.ptr<uchar>(j);
		for (int i = 0;i < nx; i++){
			//处理像素
			data[i] = (data[i]/div)*div + (div>>1);	
		}//一行结束
	}
}

int main(int argc,char ** argv){
	cv::Mat image = cv::imread("/home/atom/Desktop/tu.jpeg"/*,CV_LOAD_IMAGE_GRAYSCALE*/);
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

