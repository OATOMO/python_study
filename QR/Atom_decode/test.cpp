#include <iostream>
#include <zxing/common/Array.h>
#include <zxing/common/Counted.h>
#include <zxing/Binarizer.h>
#include <zxing/BinaryBitmap.h>
#include <zxing/MultiFormatReader.h>
#include <zxing/ReaderException.h>
#include <zxing/common/GlobalHistogramBinarizer.h>
#include <zxing/common/HybridBinarizer.h>
#include <zxing/common/GreyscaleLuminanceSource.h>
#include <zxing/DecodeHints.h>

#include <zxing/qrcode/QRCodeReader.h>
#include <zxing/multi/qrcode/QRCodeMultiReader.h>
#include <zxing/multi/ByQuadrantReader.h>
#include <zxing/multi/GenericMultipleBarcodeReader.h>
#include <zxing/common/StringUtils.h>
#include <syslog.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//-----------------------------------------------
using namespace std;
using namespace zxing;
using namespace zxing::multi;
using namespace zxing::qrcode;



int main(int argc,char ** argv){
		
	
	cv::Mat image = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
	

	//---------
	const int64 start = cv::getTickCount();
	//---------

	ArrayRef<char> data((char *)image.data,image.cols * image.rows);
	Ref<LuminanceSource> source(
					new GreyscaleLuminanceSource(data,image.cols,image.rows,
							0,0,image.cols,image.rows));
	Ref<Binarizer> binarizer(new HybridBinarizer(source));
	Ref<BinaryBitmap> bitmap(new BinaryBitmap(binarizer));
	//DecodeHints hints(DecodeHints::DEFAULT_QR_HINT);
	/*
	 *DecodeHints 类型用来告诉解码器,码大概会是什么类型
	 * */
	DecodeHints hints(DecodeHints::DEFAULT_HINT);
	MultiFormatReader reader;
	Ref<Result> result(reader.decode(bitmap, hints));

	//---------
	double duration = (cv::getTickCount() - start)/cv::getTickFrequency();
    std::cout << "proccess " << duration << "s" << std::endl;
	//---------
    cout << result->getText()->getText().c_str() << endl;



return 0;
}

