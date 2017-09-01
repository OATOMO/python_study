#include "mycube.h"
#include <QDebug>

myCube::myCube(QWidget * parent):QGLWidget(parent){
//	initWidget();
	initializeGL();
	clk.start(30);
	QObject::connect(&clk,SIGNAL(timeout()),this,SLOT(updateWindow()));
}

myCube::~myCube(){
}

void myCube::initializeGL(){
	loadGLTextures();
	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void myCube::initWidget(){
	setGeometry(0,200, 640, 480);
	setWindowTitle(tr("opengl demo"));
}

void myCube::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef( 0.0, 0.0, -6.0);//沿坐标轴移动
	glRotatef(m_x, 1.0, 0.0, 0.0);//旋转
	glRotatef(m_y, 0.0, 1.0, 0.0);
	glRotatef(m_z, 0.0, 0.0, 1.0);
	//绑定纹理特性
	glBindTexture(GL_TEXTURE_2D, textur);
	glBegin(GL_QUADS);
		glNormal3f(0.0, 0.0, 1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 1.0);

		glNormal3f(0.0, 0.0, -1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, -1.0);

		glNormal3f(0.0, 1.0, 0.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, 1.0, 1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, -1.0);

		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, -1.0, -1.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(1.0, -1.0, -1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);

		glNormal3f(1.0, 0.0, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, -1.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, -1.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 1.0);

		glNormal3f(-1.0, 0.0, 0.0);
		glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, -1.0);
		glTexCoord2f(1.0, 0.0); glVertex3f(-1.0, -1.0, 1.0);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, -1.0);
	glEnd();//glBegin(GL_QUADS);
}


void myCube::resizeGL(int width, int height){
	if (0 == height) {
	   height = 1;
	}

	glViewport(0, 0, (GLint)width, (GLint)height);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	//gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);

	GLdouble aspectRatio = (GLfloat)width / (GLfloat)height;
	GLdouble zNear = 0.1;
	GLdouble zFar = 100.0;

	GLdouble rFov = 50.0 * 3.14159265 / 180.0;
	glFrustum(-zNear * tan(rFov / 2.0) * aspectRatio,
		zNear * tan(rFov / 2.0) * aspectRatio,
		-zNear * tan(rFov / 2.0),
		zNear * tan(rFov / 2.0),
		zNear, zFar);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myCube::updateWindow()
{
	m_x += 1;
	m_y += 2;
	m_z += 2;
	updateGL();//刷新界面
}


void myCube::loadGLTextures()
{
	QImage tex;
	QImage buf;

	if (!buf.load("/home/atom/Desktop/cube.bmp"))
	{
		qWarning("load image failed!");
		QImage dummy(128, 128, QImage::Format_RGB32);
		dummy.fill(Qt::red);
		buf = dummy;

	}

	tex = QGLWidget::convertToGLFormat(buf);
	glGenTextures(1, &textur);
	glBindTexture(GL_TEXTURE_2D, textur);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
		GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

