/*
 *ZXing项目的示例程序对于摄像头的控制写的非常全面，ZBar的没有
 *ZBar基于C语言编写，解码效率高于ZXing项目
 *ZBar是日本人写的，对于中文解析会乱码这个肯定有人遇到过的，ZXing不会乱码
 *扫描框的绘制，ZXing的扫描框绘制是自定义View的，截取区域不好控制（至少我没控制好），ZBar的可以自定义，只要你会计算截取区域
 * */
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
#include "zbar.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace zbar;
using namespace cv;

void onMouse(int event,int x,int y,int flags,void *param);

int main(int argc,char ** argv){
	if(argc <= 1){
		cout << "user: " << argv[0] << " [image]" << endl;
		return -1;
	}
	//string filename = argv[1];
	clock_t start,end;
	double duration;


	cv::Mat image_src = cv::imread(argv[1],0);
	cv::Mat image;
	image_src.copyTo(image);

	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::setMouseCallback("Image",onMouse,reinterpret_cast<void *>(&image));//注册鼠标回调函数
	cv::waitKey();

	start = getTickCount();
	//二值化
	cv::threshold(image,image,100, 	//临界值
					255,			//最大值
					CV_THRESH_BINARY);//模式   
	cv::imshow("Image",image);
	duration = (getTickCount()-start)/getTickFrequency();
	cout << "处理二值化用时" << duration << "s" <<  endl;

	cv::waitKey();

	zbar::ImageScanner scanner;
	scanner.set_config(ZBAR_NONE,ZBAR_CFG_ENABLE,1);

	const void * raw = image.data;
	int width = image.cols;
	int height = image.rows; 

	zbar::Image procImage(width,height,"Y800",raw,width * height);


	start = getTickCount();
	int n = scanner.scan(procImage);  
	//cout << "n ->" << n << endl;
	duration = (getTickCount()-start)/getTickFrequency();
	cout << "扫描用时" << duration << "s" <<  endl;

	std::string strTemp=""; 

	zbar::Image::SymbolIterator symbol = procImage.symbol_begin();
	cout << "decoded " << symbol->get_type_name()<<endl;  
	for(;symbol != procImage.symbol_end();++symbol){
		strTemp =strTemp +symbol->get_data()+";";  
		cout << "decoded " << symbol->get_type_name()
			 <<" symbol \"" << symbol->get_data() << '"' << endl;  
	}  
	cout << "strTemp -> " << strTemp << endl;

	cout << "format " << procImage.get_format() << endl;

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
