/*
 * v4l2捕获接口
 * grab.c
 * */
#include "grab_v4l2.hpp"


/*usage step 
 * 1.
 *	-open("dev");
 * 2.
 * 	-fill struct self_fmt;
 * 3.
 * 	-initCamera(&vd);
 * */
int initCamera(struct video_dev * pvd){
#ifdef PRINTINFO
	showCap(pvd);
#endif
   	setFmt(pvd);	
	//whiteBalance(pvd);
	setExposure(pvd,4);//自动曝光
	reqBufs(pvd);
return 0;
}

int showCap(struct video_dev * pvd){
	/*获取显示设备能力*/
	int retval;
	retval = ioctl(pvd->fb,VIDIOC_QUERYCAP,&pvd->cap);
	if(retval != 0){
	printf("get capability error!!!!!!!\n");	
	return retval;
	}
	printf("| Driver Name: %s\n| Card Name: %s\n| Bus info %s\n| Driver Version:%u.%u.%u\n",
		pvd->cap.driver,pvd->cap.card,pvd->cap.bus_info,
       (pvd->cap.version>>16)&0XFF,
       (pvd->cap.version>>8)&0XFF,
        pvd->cap.version&0XFF);

  	pvd->fmtdesc.index = 0;
  	pvd->fmtdesc.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  	printf("Support format:\n");
  	while(ioctl(pvd->fb, VIDIOC_ENUM_FMT, &pvd->fmtdesc) != -1)
  	{
    	printf("\t%d.%s -> pixelformat:%c%c%c%c\n",
				pvd->fmtdesc.index+1,pvd->fmtdesc.description,
        		(pvd->fmtdesc.pixelformat)&0XFF,
       			(pvd->fmtdesc.pixelformat>>8)&0XFF,
				(pvd->fmtdesc.pixelformat>>16)&0XFF,
				(pvd->fmtdesc.pixelformat>>24) & 0XFF);
   	 	pvd->fmtdesc.index++;
 	}
/*	cv::Mat image = cv::imread("./temp.bmp");
	cv::namedWindow("image");
	cv::imshow("image",image);
*/
    struct v4l2_queryctrl queryctrl;

    isv4l2Control(pvd,VIDIOC_REQBUFS,&queryctrl) ;
    printf("%s : value max :%d,val min %d.!!!!!!!!!!!!!!\n",queryctrl.name,queryctrl.maximum,queryctrl.minimum);
return retval;
}


int setFmt(struct video_dev *pvd){
	/*设置格式,并打印*/
	int retval;
 	//设置FMT
  	pvd->fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  	pvd->fmt.fmt.pix.width =  pvd->self_fmt->width;
  	pvd->fmt.fmt.pix.height = pvd->self_fmt->height;
  	//pvd->fmt.fmt.pix.colorspace = 7;
  	//pvd->fmt.fmt.pix.bytesperline = pvd->fmt.fmt.pix.width * 4;
  	pvd->fmt.fmt.pix.pixelformat= pvd->self_fmt->pixelformat;
    								//V4L2_PIX_FMT_JPEG;
    								//V4L2_PIX_FMT_GREY;
  	pvd->fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
  	retval = ioctl(pvd->fb, VIDIOC_S_FMT, &pvd->fmt);


#ifdef PRINTINFO
  	//查询FMT
  	pvd->fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
  	ioctl(pvd->fb, VIDIOC_G_FMT, &pvd->fmt);
  	printf("Current data format information:\n\twidth:%d\n\theight:%d\n",
    	    pvd->fmt.fmt.pix.width,pvd->fmt.fmt.pix.height);
	printf("Current pixelformat:%c%c%c%c\n",
        		(pvd->fmt.fmt.pix.pixelformat)&0XFF,
       			(pvd->fmt.fmt.pix.pixelformat>>8)&0XFF,
				(pvd->fmt.fmt.pix.pixelformat>>16)&0XFF,
				(pvd->fmt.fmt.pix.pixelformat>>24) & 0XFF);
  	
#endif

    struct v4l2_streamparm *setfps;
    setfps = (struct v4l2_streamparm *) calloc(1, sizeof(struct v4l2_streamparm));
    memset(setfps, 0, sizeof(struct v4l2_streamparm));
    setfps->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    setfps->parm.capture.timeperframe.numerator = 1;
    setfps->parm.capture.timeperframe.denominator = 60;
    setfps->parm.capture.readbuffers = 1;
    retval = ioctl(pvd->fb, VIDIOC_S_PARM, setfps);
    if (retval != 0)
        printf("frame rate set faild !!!!!!!!!\n");
return retval;
}

int isv4l2Control (struct video_dev *pvd, int control, struct v4l2_queryctrl *queryctrl)
{
    int err = 0;

    queryctrl->id = control;
    if ((err = ioctl (pvd->fb, VIDIOC_QUERYCTRL, queryctrl)) < 0) {
        fprintf (stderr, "ioctl querycontrol error %d \n", errno);
    } else if (queryctrl->flags & V4L2_CTRL_FLAG_DISABLED) {
        fprintf (stderr, "control %s disabled \n", (char *) queryctrl->name);
    } else if (queryctrl->flags & V4L2_CTRL_TYPE_BOOLEAN) {
        return 1;
    } else if (queryctrl->type & V4L2_CTRL_TYPE_INTEGER) {
        return 0;
    } else {
        fprintf (stderr, "contol %s unsupported  \n", (char *) queryctrl->name);
    }

    return -1;
}
int whiteBalance(struct video_dev *pvd){
return 0;
}
/*usage :
 * 	value :0 auto exposure
 * 	value :not 0, set exposure value
 * */
int setExposure(struct video_dev *pvd,unsigned value){
int retval;
	struct v4l2_control ctrl;
	if(value == 0){//自动曝光
		ctrl.id = V4L2_CID_EXPOSURE_AUTO;
		ctrl.value = 0;
		retval = ioctl(pvd->fb,VIDIOC_S_CTRL,&ctrl);	
	}
	else if(value != 0){
		ctrl.id = V4L2_CID_EXPOSURE_AUTO;
		ctrl.id = 1;
		retval = ioctl(pvd->fb,VIDIOC_S_CTRL,&ctrl);

		/*ctrl.id = V4L2_CID_EXPOSURE_ABSOLUTE;*/
		ctrl.id = V4L2_CID_EXPOSURE;
		ctrl.value = value;
		retval = ioctl(pvd->fb, VIDIOC_S_CTRL,&ctrl);
	}
#ifdef PRINTINFO
	ctrl.id = V4L2_CID_EXPOSURE_ABSOLUTE;
	/*ctrl.id = V4L2_CID_EXPOSURE_AUTO;*/
	retval = ioctl(pvd->fb, VIDIOC_G_CTRL, &ctrl);
	printf("exposure %d\n",ctrl.value);
#endif
return retval;
}

int reqBufs(struct video_dev * pvd){
	int retval;
  	//申请缓冲,并把缓存放入队列
  	pvd->req.count = N_BUFFERS;
  	pvd->req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  	pvd->req.memory = V4L2_MEMORY_MMAP;
  	ioctl(pvd->fb,VIDIOC_REQBUFS,&pvd->req);
  	pvd->buffers = (struct buffer*)calloc(pvd->req.count,sizeof(struct buffer));
  	unsigned n_buffers = 0;
  	for (n_buffers = 0; n_buffers < pvd->req.count;n_buffers++){
        memset(&pvd->buf,0,sizeof(pvd->buf));
        pvd->buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        pvd->buf.memory = V4L2_MEMORY_MMAP;
        pvd->buf.index = n_buffers;
        if(ioctl(pvd->fb,VIDIOC_QUERYBUF,&pvd->buf) == -1){
      		printf("query memory error !!!\n");
      		close(pvd->fb);
      	return -1;
    	}//if
        pvd->buffers[n_buffers].length = pvd->buf.length;
        pvd->buffers[n_buffers].start  = mmap(NULL,pvd->buf.length,PROT_READ | PROT_WRITE,
                                MAP_SHARED,pvd->fb,pvd->buf.m.offset);
        if (MAP_FAILED == pvd->buffers[n_buffers].start){
            printf("MAP memory error !!!\n");
            close(pvd->fb);
            return -1;
        }//if
        printf ("%d buffer start -> 0X%p,length -> %d\n",
            n_buffers,pvd->buffers[n_buffers].start,pvd->buffers[n_buffers].length);
    }
    pvd->framebuff = (char *)malloc(pvd->buf.length);

	//
 	unsigned int i;
  	for(i = 0; i < pvd->req.count; i++){
        pvd->buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        pvd->buf.memory = V4L2_MEMORY_MMAP;
        pvd->buf.index = i;
        ioctl(pvd->fb,VIDIOC_QBUF,&pvd->buf);
  		}
return retval;
}
static int
video_enable (struct video_dev *pvd)
{
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    int ret;

    ret = ioctl (pvd->fb, VIDIOC_STREAMON, &type);
    if (ret < 0) {
        fprintf (stderr, "Unable to %s capture: %d.\n", "start", errno);
        return ret;
    }
    pvd->isStreaming = 1;

    return 0;
}

static int
video_disable (struct video_dev *pvd)
{
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    int ret;

    ret = ioctl (pvd->fb, VIDIOC_STREAMOFF, &type);
    if (ret < 0) {
        fprintf (stderr, "Unable to %s capture: %d.\n", "stop", errno);
        return ret;
    }
    pvd->isStreaming = 0;
    return 0;
}


int Grab(struct video_dev * pvd){
	int retval;	
    if(!pvd->isStreaming){
        video_enable(pvd);
    }

    //DQBUF
    pvd->buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    pvd->buf.memory = V4L2_MEMORY_MMAP;
    ioctl(pvd->fb,VIDIOC_DQBUF,&pvd->buf);
    printf("DQBUF_number -> *** %d ***\n",pvd->buf.index);


    memcpy(pvd->framebuff,pvd->buffers[pvd->buf.index].start,pvd->buffers[pvd->buf.index].length);
	if(pvd->fmt.fmt.pix.pixelformat == V4L2_PIX_FMT_JPEG){
        char path[20];
        snprintf(path,sizeof(path),"./image.temp");
        int fdyuyv = open(path,O_WRONLY|O_CREAT,00700);
        //int resultyuyv = write(fdyuyv,pvd->buffers[pvd->buf.index].start,pvd->buffers[pvd->buf.index].length);
        int resultyuyv = write(fdyuyv,pvd->framebuff,pvd->buffers[pvd->buf.index].length);
        printf("TK--------->>>resultyuyv is %d\n",resultyuyv);
        close(fdyuyv);
    }

    //QBUF
    pvd->buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    pvd->buf.memory = V4L2_MEMORY_MMAP;
    ioctl(pvd->fb,VIDIOC_QBUF,&pvd->buf);
    printf("QBUF_number -> *** %d ***\n",pvd->buf.index);

#if 0
    int type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ioctl(pvd->fb,VIDIOC_STREAMOFF,&type);
#endif
return retval;
}

#if 0
int grab_test(struct video_dev *pvd){
  //查询设备
  ioctl(pvd->fb,VIDIOC_QUERYCAP,&pvd->cap);
	printf("Driver Name: %s\n Card Name: %s \nBus info : %s\nDriver Version:%u.%u.%u\n",
        pvd->cap.driver,pvd->cap.card,pvd->cap.bus_info,
        (pvd->cap.version>>16)&0XFF,
        (pvd->cap.version>>8)&0XFF,
        pvd->cap.version&0XFF);

  //查询支持类型
  pvd->fmtdesc.index = 0;
  pvd->fmtdesc.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  printf("Support format:\n");
  while(ioctl(pvd->fb, VIDIOC_ENUM_FMT, &pvd->fmtdesc) != -1)
  {
    printf("\t%d.%s\n",pvd->fmtdesc.index+1,pvd->fmtdesc.description);
    pvd->fmtdesc.index++;
  }

  //设置FMT
  pvd->fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  pvd->fmt.fmt.pix.width =  320;
  pvd->fmt.fmt.pix.height = 240;
  //pvd->fmt.fmt.pix.colorspace = 7;
  //pvd->fmt.fmt.pix.bytesperline = pvd->fmt.fmt.pix.width * 4;
  pvd->fmt.fmt.pix.pixelformat= V4L2_PIX_FMT_RGB24;
      //pvd->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_JPEG;
      //pvd->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_GREY;
  pvd->fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
  ioctl(pvd->fb, VIDIOC_S_FMT, &pvd->fmt);



  //查询FMT
  pvd->fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
  ioctl(pvd->fb, VIDIOC_G_FMT, &pvd->fmt);
  printf("Current data format information:\n\twidth:%d\n\theight:%d\n",
        pvd->fmt.fmt.pix.width,pvd->fmt.fmt.pix.height);
  printf("Current color:\n %d \n",pvd->fmt.fmt.pix.colorspace);
  //设置FMT
/*  pvd->fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  pvd->fmt.fmt.pix.width =  1024;
  pvd->fmt.fmt.pix.height = 768;
  pvd->fmt.fmt.pix.colorspace = 7;
  //pvd->fmt.fmt.pix.pixelformat= V4L2_PIX_FMT_RGB24;
  pvd->fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_GREY;
  pvd->fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
  ioctl(pvd->fb, VIDIOC_S_FMT, &pvd->fmt);
*/

  //申请缓冲
  pvd->req.count = 4;
  pvd->req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  pvd->req.memory = V4L2_MEMORY_MMAP;
  ioctl(pvd->fb,VIDIOC_REQBUFS,&pvd->req);
  pvd->buffers = (struct buffer*)calloc(pvd->req.count,sizeof(struct buffer));
  unsigned n_buffers = 0;
  for (n_buffers = 0; n_buffers < pvd->req.count;n_buffers++){
    struct v4l2_buffer buf;
    memset(&buf,0,sizeof(buf));
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    buf.index = n_buffers;
    if(ioctl(pvd->fb,VIDIOC_QUERYBUF,&buf) == -1){
      printf("query memory error !!!\n");
      close(pvd->fb);
      return -1;
    }//if
    pvd->buffers[n_buffers].length = buf.length;
    pvd->buffers[n_buffers].start  = mmap(NULL,buf.length,PROT_READ | PROT_WRITE,
                                MAP_SHARED,pvd->fb,buf.m.offset);
    if (MAP_FAILED == pvd->buffers[n_buffers].start){
      printf("MAP memory error !!!\n");
      close(pvd->fb);
      return -1;
    }//if
    printf ("%d buffer start -> 0X%p,length -> %d\n",
            n_buffers,pvd->buffers[n_buffers].start,pvd->buffers[n_buffers].length);
  }

  //
  unsigned int i;
  enum v4l2_buf_type type;
  for(i = 0; i < 4; i++){
    struct v4l2_buffer buf;
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    buf.index = i;
    ioctl(pvd->fb,VIDIOC_QBUF,&buf);
  }
  type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  ioctl(pvd->fb,VIDIOC_STREAMON,&type);

  struct v4l2_buffer buf;
  buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
  buf.memory = V4L2_MEMORY_MMAP;
  ioctl(pvd->fb,VIDIOC_DQBUF,&buf);

  //jpeg的存储方式
  if(pvd->fmt.fmt.pix.pixelformat == V4L2_PIX_FMT_JPEG){
  char path[20];
  snprintf(path,sizeof(path),"./image%d",buf.index);
  int fdyuyv = open(path,O_WRONLY|O_CREAT,00700);
  int resultyuyv = write(fdyuyv,pvd->buffers[buf.index].start,pvd->buffers[buf.index].length);
  printf("TK--------->>>resultyuyv is %d\n",resultyuyv);
  close(fdyuyv);
  }
  //RGB的存储方式
  if((pvd->fmt.fmt.pix.pixelformat) == V4L2_PIX_FMT_RGB24){
    printf ("save image ...\n");
    /*
    cv::Mat img(pvd->fmt.fmt.pix.width,
                pvd->fmt.fmt.pix.height,
                CV_8UC3,
                (pvd->buffers[buf.index].start));
    cv::imwrite("./temp.bmp",img);
    */
#if 0
    tom::whiteBalanceTest((uchar *)pvd->buffers[buf.index].start,
                        pvd->fmt.fmt.pix.width,
                        pvd->fmt.fmt.pix.height,
                        3);
#endif    
    tom::saveBmp((uchar *)pvd->buffers[buf.index].start,
            "./temp.bmp",
            pvd->fmt.fmt.pix.width,
            pvd->fmt.fmt.pix.height);
    tom::whiteBalanceTest_2("./temp.bmp");
  }
  ////


return 0;
}
#endif 
