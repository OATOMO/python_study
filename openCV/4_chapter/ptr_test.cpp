/*	
 *	测试ptr模板 和直接地址访问的效率
 *	mat.ptr<cv::Vec3b>(row) //返回指针
 *	cv::Vec3b * p = mat.ptr<cv::Vec3b>(row,col) //
 *	p->val[0] = 255;
 *	好处是可以抛出异常
 *	-----------------
 *	再试一下at调用
 *	mat.at<cv::Vec3b>(row,col)[0] = 255;
 *	-----------------
 *	再试一下迭代器遍历
 *	auto it = mrt.begin<cv::Vec3b>();
 *	auto it_end = mat.end<cv::Vec3b>();
 *	********************result
 * pinter pro time = 0.11925 s
 * ptr pro time = 0.33282 s
 * optimize ptr pro time = 0.30203 s
 * at  pro time = 0.42764 s
 * it  pro time = 0.6432 s
 * */
#include <sys/types.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
using namespace std;

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

int main(int argc,char ** argv){
	cv::Mat image(2400,3600,CV_8UC3);


	::proTime();
	//直接地址遍历
	int line = image.cols  * image.elemSize();
	cout << "line = " << line <<endl;
	int elem = image.elemSize();
	cout << "elem = " << elem << endl;
	for (int row = 0;row < image.rows;row++){
		for(int col = 0;col < image.cols;col++){
			image.data[row*line+col*elem + 0] = 250;
			image.data[row*line+col*elem + 1] = 100;
			image.data[row*line+col*elem + 2] = 0;

		}
	}
	::proTime("pinter");
	cv::namedWindow("Image");
	cv::imshow("Image",image);
	cv::waitKey();

	//使用ptr遍历Mat
	::proTime();
	for (int row = 0; row < image.rows;row++){
		for (int col = 0; col < image.cols;col++){
			image.ptr<cv::Vec3b>(row,col)->val[0] = 0;
			image.ptr<cv::Vec3b>(row,col)->val[1] = 250;
			image.ptr<cv::Vec3b>(row,col)->val[2] = 0;
		}
	}
	::proTime("ptr");
	cv::imshow("Image",image);
	cv::waitKey();
	//优化过的ptr
	::proTime();
	for (int row = 0; row < image.rows;row++){
		for (int col = 0; col < image.cols;col++){
			cv::Vec3b * p = image.ptr<cv::Vec3b>(row,col);
			p->val[0] = 0;
			p->val[1] = 0;
			p->val[2] = 250;
			/**(p+0) = 0;	*/
			/**(p+1) = 0;	*/
			/**(p+2) = 250;*/	
		}
	}
	::proTime("optimize ptr");
	cv::imshow("Image",image);
	cv::waitKey();
	//使用at来遍历
	::proTime();
	for (int row = 0; row < image.rows;row++){
		for (int col = 0; col < image.cols;col++){
			cv::Vec3b &mat = image.at<cv::Vec3b>(row,col);
			mat[0] = 100;
			mat[1] = 100;
			mat[2] = 100;
		}
	}
	::proTime("at ");
	cv::imshow("Image",image);
	cv::waitKey();
	//使用迭代器遍历
	::proTime();
	cv::MatIterator_<cv::Vec3b> it = image.begin<cv::Vec3b>();
	cv::MatIterator_<cv::Vec3b> it_end = image.end<cv::Vec3b>();	
	for (;it < it_end;it++){
		(*it).val[0] = 250;
		(*it).val[1] = 100;
		(*it).val[2] = 0;
	}
	::proTime("it ");
	cv::imshow("Image",image);
	cv::waitKey();
}//end main
