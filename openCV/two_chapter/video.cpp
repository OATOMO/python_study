#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap(0); // 打开摄像头0
	if (!cap.isOpened())  // 异常处理
	    {
	       cout << "Cannot open the video cam" << endl;
	       waitKey(60000);
	       return -1;
	    }

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //输入流的宽
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //输入流的高

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //创建一个窗体

    while (1)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // 获取一帧
	if (!bSuccess) //异常处理
    {
        cout << "Cannot read a frame from video stream" << endl;
        break;
    }

   imshow("MyVideo", frame); //显示获取到的视频帧

   if (waitKey(30) == 27) //按键退出
  {
     cout << "esc key is pressed by user" << endl;
     break;
  }
  }
	waitKey(60000);
	return 0;

}
