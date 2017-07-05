/*图像金字塔只能成倍的缩小或放大
 * ****************************
 * 高斯金字塔(Gaussian pyramid):
 *		用来向下采样(缩小)
 *		1.获取G(I+1) 将G(I) 与高斯内核卷积(高斯内核就是一个矩阵5x5)
 *		2.将所有偶数行和列去除
 *
 * 拉普拉斯金字塔(Laplacian pyramid):
 *		用来从金字塔底层图像重建上层未采样图像
 *		1.首先将图像放大两倍,新增的以0填充
 *		2.高斯内核(乘以4)与放大后的内核卷积
 * */
#include <sys/types.h>
#include <opencv2/opencv.hpp>
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

int main(){
	/*原图用高斯缩小后用拉普拉斯放大*/
	cv::Mat image = cv::imread("/home/atom/Desktop/tu.jpeg");
	cv::Mat gDes,lDes;
	cv::pyrDown(image,gDes);
	cv::pyrUp(gDes,lDes);

//	cv::imshow("gDes",gDes);
	cv::imshow("image",image);
	cv::imshow("lDes",lDes);

cv::waitKey();

return 0;
}
