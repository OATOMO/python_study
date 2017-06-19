#include "grab_gui.h"
#include "ui_grab_gui.h"
#include "v4l2_sdk/grab_v4l2.hpp"
#include <fcntl.h>
#include <iostream>
#include <unistd.h>
#include <linux/videodev2.h>
#include <QPixmap>
//#include <stdio.h>




grab_gui::grab_gui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grab_gui)
{
    ui->setupUi(this);
    this->pvd = (struct video_dev *)malloc(sizeof(struct video_dev));
    pvd->fb = open("/dev/video0",O_RDWR);
    pvd->self_fmt  = (struct self_fmt *)malloc(sizeof(struct self_fmt));
    pvd->self_fmt->width = 320;
    pvd->self_fmt->height =240;
    pvd->self_fmt->pixelformat = V4L2_PIX_FMT_JPEG;
    pvd->isStreaming = 0;

    initCamera(pvd);


}

grab_gui::~grab_gui()
{
    delete ui;
    ::close(pvd->fb);
    free(pvd->buffers);
    free(pvd->self_fmt);
    free(pvd);
}

void grab_gui::on_grabButton_clicked()
{
    Grab(pvd);
   pix = new QPixmap("./image.temp");
    ui->imageLabel->setPixmap(*pix);
}
