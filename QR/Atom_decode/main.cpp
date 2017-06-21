#include "decodeEnter.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

 int n_proc ; 
 int n_failed; 
cv::Mat image;

void scandir(char *path);


int main(int argc,char ** argv){
		if (argc != 2){
			printf("usage :%s <dirname> ",argv[0]);
		}

		::scandir(argv[1]);

		double rate = (n_failed * 100 /  n_proc);
		printf("n_faild -> %d,n_proc -> %d\n",n_failed,n_proc);
		printf("failed rate %2.1f\%\n",rate);
		//cv::Mat image = cv::imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
		//	std::cout << zhijin::decodeEnter(image,QRCODE,
		//				0,0,image.cols,image.rows) << std::endl;
return 0;
}


void scandir(char *path){
		DIR * dp;
		struct dirent * entry;
		struct stat statbuf;

	if((dp = opendir(path)) == NULL){
		printf("cannot open directory:%s\n",path);
	}
	chdir(path);
	while((entry = readdir(dp)) != NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode)){ //is dir proc
			if(strcmp(".",entry->d_name)==0 || strcmp("..",entry->d_name)==0 )
					continue;
			scandir(entry->d_name);
		}//endif
		else { //is image proc
			printf("\nfilename -> %s\n",entry->d_name);
#if 1
			image = cv::imread(entry->d_name,CV_LOAD_IMAGE_GRAYSCALE);
			try{
				n_proc++;
				std::string s = zhijin::decodeEnter(image,QRCODE,0,0,image.cols,image.rows);	
			}//try
			catch (zxing::Exception &e){
				n_failed++;
				char s[20];
				printf("image %s proc failed ... T_T\n",entry->d_name);
				sprintf(s,"/home/atom/Desktop/datacode/failed/%s",entry->d_name);
				cv::imwrite(s,image);
			}//catch
#endif
		}//end else
	}//while
	chdir("..");
	closedir(dp);
return ;
}
