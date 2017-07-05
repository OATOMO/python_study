/*未完成*/
#include <iostream>
#include <opencv2/opencv.hpp>

class ColorHistogram{
private:
	int histSize[3];			//每个维度的大小
	float hranges[2];			//值的范围
	const float * ranges[3];	//每个维度的范围
	int channels[3];			//需要处理的通道数
public:
	ColorHistogram(){
		/*准备用于彩色图像的默认参数,
		 * 每个维度的范围和大小是相等的*/
		histSize[0] = histSize[1] = histSize[2] = 256;
		hranges[0] = 0.0; //范围 0~256
		hranges[1] = 256.0;
		ranges[0] = hranges; //这个类中,所有通道的范围都相等
		ranges[1] = hranges;
		ranges[2] = hranges;
		channels[0] = 0;	//三个通道
		channels[1] = 1;
		channels[2] = 2;
	}//end ColorHistogram

	/*计算直方图*/
	cv::Mat getHistogram(const cv::Mat &image){
		cv::Mat hist;

		//计算
		cv::calcHist(&image,		
						1,			//单个图像直方图
						channels,	//用到的通道
						cv::Mat(),	//不是用掩码
						hist,		//结果
						3,			//这是一个三维直方图
						histSize,	//箱子数量
						ranges); 	//像素值的范围
		return hist;
	}//end getHistogram

	/*计算直方图,返回大型稀疏矩阵*/
	cv::SparseMat getSparseHistogram(const cv::Mat &image){
		cv::SparseMat hist(3,histSize,CV_32F);
		//计算
		cv::calcHist(&image,		
						1,			//单个图像直方图
						channels,	//用到的通道
						cv::Mat(),	//不是用掩码
						hist,		//结果
						3,			//这是一个三维直方图
						histSize,	//箱子数量
						ranges); 	//像素值的范围
		return hist;
	}
};//end COlorHistogram

int main(int argc ,char ** argv){
	cv::Mat image = cv::imread(argv[1]);
	ColorHistogram h;
	
	cv::Mat hist = h.getHistogram(image);
	std::cout << "hist size -> " << hist.size << std::endl;
	std::cout << "rows -> " << hist.rows << std::endl;
	std::cout << "clos -> " << hist.cols << std::endl;

return 0;
}
