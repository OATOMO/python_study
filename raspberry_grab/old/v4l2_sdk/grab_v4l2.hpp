/*
 * v4l2捕获接口
 * */
#ifndef __GRAB_V4L2_H
#define __GRAB_V4L2_H

#define PRINTINFO

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/videodev2.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include <memory.h>
#include <sys/ioctl.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "atom_bmp.hpp"

#define N_BUFFERS   15;


struct buffer{
  void *start;
  unsigned int length;
};

//self想要的宽,高,pixelformat;
struct self_fmt{
	int width;
	int height;
	int pixelformat;
};

struct video_dev{
	int fb;//设备描述符

	/*user VIDIOC_QUERYCAP
	查询设备能力*/
	struct v4l2_capability cap;
	/*VIDIOC_ENUM_FMT
	查询设备所支持的格式*/
	struct v4l2_fmtdesc fmtdesc;
	/*VIDIOC_S_FMT,VIDIOC_G_FMT
	查看或设置当前格式*/
	struct v4l2_format  fmt;
	/*VIDIOC_REQBUFS
	向设备申请缓冲区*/
	struct v4l2_requestbuffers req;
	/*
    VIDIOC_QUERYBUF
    */
	struct v4l2_buffer buf;


	//指向映射到的内存
	struct buffer * buffers;
    //
    char * framebuff;

	//self想要的宽,高,pixelformat;
	struct self_fmt * self_fmt;

    int isStreaming;
};



int  grab_test(struct video_dev *pvd);
int initCamera(struct video_dev * pvd);
int showCap(struct video_dev * pvd);
int setFmt(struct video_dev *pvd);
int whiteBalance(struct video_dev *pvd);
int setExposure(struct video_dev *pvd,unsigned value);
int reqBufs(struct video_dev * pvd);
int Grab(struct video_dev * pvd);
int isv4l2Control (struct video_dev *pvd, int control, struct v4l2_queryctrl *queryctrl);

#endif __GRAB_V4L2_H
