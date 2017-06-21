#include "decodeEnter.hpp"

using namespace std;
using namespace zxing;
using namespace zxing::multi;
using namespace zxing::qrcode;

namespace zhijin{
			
	const char * decodeEnter(cv::Mat &image,int type,
				int left,int top,int width,int height){
			cv::Mat tmpImage = image;
			if(type == QRCODE){
		//	try{
				printf("proccess zxing \n");
				ArrayRef<char> data((char *)tmpImage.data,tmpImage.cols * tmpImage.rows);	
				Ref<LuminanceSource> source(
                    	new GreyscaleLuminanceSource(data,image.cols,image.rows,
                        0,0,image.cols,image.rows));
				Ref<Binarizer> binarizer(new HybridBinarizer(source));
    			Ref<BinaryBitmap> bitmap(new BinaryBitmap(binarizer));
				
				DecodeHints hints(DecodeHints::DEFAULT_HINT);
  
      			MultiFormatReader reader;
      			Ref<Result> result(reader.decode(bitmap, hints));
				cout << result->getText()->getText().c_str() << endl;
				return result->getText()->getText().c_str();
		//	}//try
			//catch (zxing::Exception &e){
			//	printf("!!!!!无法处理 放入/desktop/notprocess/ 文件夹\n");				
			//	cv::imwrite();
			//}//catch
			}//if
			else if(type == BARCODE){
				printf("proccess zbar \n");
			}
	}

}//end namespace 

