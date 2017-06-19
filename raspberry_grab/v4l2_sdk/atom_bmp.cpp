#include "atom_bmp.hpp"

namespace tom{

void saveBmp(uchar * pdata,const char * bmp_file, int width, int height)
{      //分别为rgb数据，要保存的bmp文件名，图片长宽
       int size = width*height*3*sizeof(char); // 每个像素点3个字节
       // 位图第一部分，文件信息
       BMPFILEHEADER_T bfh;
       bfh.bfType = (WORD)0x4d42;  //bm
       bfh.bfSize = size  // data size
              + sizeof( BMPFILEHEADER_T ) // first section size
              + sizeof( BMPINFOHEADER_T ) // second section size
              ;
       bfh.bfReserved1 = 0; // reserved
       bfh.bfReserved2 = 0; // reserved
       bfh.bfOffBits = sizeof( BMPFILEHEADER_T )+ sizeof( BMPINFOHEADER_T );//真正的数据的位置

       // 位图第二部分，数据信息
       BMPINFOHEADER_T bih;
       bih.biSize = sizeof(BMPINFOHEADER_T);
       bih.biWidth = width;
       bih.biHeight = -height;//BMP图片从最后一个点开始扫描，显示时图片是倒着的，所以用-height，这样图片就正了
       bih.biPlanes = 1;//为1，不用改
       bih.biBitCount = 24;
       bih.biCompression = 0;//不压缩
       bih.biSizeImage = size;
       bih.biXPelsPerMeter = 2835 ;//像素每米
       bih.biYPelsPerMeter = 2835 ;
       bih.biClrUsed = 0;//已用过的颜色，24位的为0
       bih.biClrImportant = 0;//每个像素都重要
       FILE * fp = fopen( bmp_file,"wb" );
       if( !fp ) return;

       fwrite( &bfh, 8, 1,  fp );//由于linux上4字节对齐，而信息头大小为54字节，第一部分14字节，第二部分40字节，所以会将第一部分补齐为16自己，直接用sizeof，打开图片时就会遇到premature end-of-file encountered错误
       fwrite(&bfh.bfReserved2, sizeof(bfh.bfReserved2), 1, fp);
       fwrite(&bfh.bfOffBits, sizeof(bfh.bfOffBits), 1, fp);
       fwrite( &bih, sizeof(BMPINFOHEADER_T),1,fp );
       fwrite(pdata,size,1,fp);
       fclose( fp );
}


void whiteBalanceTest(uchar * data,int width,int height,int channels){
	uchar * ptr = data;
	if (channels == 3){
		int i;
		for (i = 0; i < width * height;i++){
			ptr += i*3;
			ptr[0] = uchar(*ptr * 1);
			ptr[1] = uchar(*ptr * 1);
			ptr[2] = uchar(*ptr * 1);
		}
	}
}

void whiteBalanceTest_2(const char * path){
	cv::Mat imageSource = cv::imread("./temp.bmp");
	std::vector<cv::Mat> imageRGB; 

	cv::split(imageSource, imageRGB);

	double R, G, B;  
    B = cv::mean(imageRGB[0])[0];  
    G = cv::mean(imageRGB[1])[0];  
    R = cv::mean(imageRGB[2])[0];  

    double KR, KG, KB;  
    KB = (R + G + B) / (3 * B);  
    KG = (R + G + B) / (3 * G);  
    KR = (R + G + B) / (3 * R); 

    imageRGB[0] = imageRGB[0] * KB;  
    imageRGB[1] = imageRGB[1] * KG;  
    imageRGB[2] = imageRGB[2] * KR;  

    merge(imageRGB, imageSource);
    cv::imwrite("./temp_.bmp",imageSource);  
}

};//namespace
