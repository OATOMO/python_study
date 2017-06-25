
#ifndef __ATOM_BMP_HPP
#define __ATOM_BMP_HPP
#include <stdio.h>
#include <jpeglib.h>
#include <sys/types.h>
#include <unistd.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//#include <>
namespace tom{
  typedef unsigned char uchar;
  typedef long LONG;
  typedef unsigned long DWORD;
  typedef unsigned short WORD;

  typedef struct {
          WORD    bfType;
          DWORD   bfSize;
          WORD    bfReserved1;
          WORD    bfReserved2;
          DWORD   bfOffBits;
  } BMPFILEHEADER_T;

  typedef struct{
          DWORD      biSize;
          LONG       biWidth;
          LONG       biHeight;
          WORD       biPlanes;
          WORD       biBitCount;
          DWORD      biCompression;
          DWORD      biSizeImage;
          LONG       biXPelsPerMeter;
          LONG       biYPelsPerMeter;
          DWORD      biClrUsed;
          DWORD      biClrImportant;
  } BMPINFOHEADER_T;


void saveBmp(uchar * pdata,const char * bmp_file, int width, int height );
void whiteBalanceTest(uchar * data,int width,int height,int channels);
void whiteBalanceTest_2(const char * path);
};//namespcae tom


#endif __ATOM_BMP_HPP
