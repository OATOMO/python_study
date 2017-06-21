#ifndef  __ATOM_DECODE_H
#define  __ATOM_DECODE_H
//-- standard head
#include <iostream>
#include <string>
#include <time.h>
#include <syslog.h>
//-- opencv head
#include <opencv2/opencv.hpp>
//-- zbar head
#include <zbar.h>
//-- zxing head
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
//------------------
#define BARCODE 0x1002
#define QRCODE  0x1001

namespace zhijin{
			
	const char * decodeEnter(cv::Mat &image,int type,
				int left,int top,int width,int height);
}//end namespace 
#endif  __ATOM_DECODE_H

