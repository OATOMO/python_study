#include <GL/glut.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

GLuint texture; 
/*
	1-------2
	|		|
	|		|
	0-------3
*/
GLfloat vertex[][3] = {
	{0.0,0.0,0.0},
	{0.0,1.0,0.0},
	{1.0,1.0,0.0},
	{1.0,0.0,0.0}
};


void draw(){
	cv::Mat Texture = cv::imread("/home/atom/Desktop/cube.bmp"); 	
	if(Texture.channels() != 3){
		printf("Texture.channels() != 3") ;
		return ;
	}//加载纹理
	
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glEnable(GL_TEXTURE_2D);//启动纹理映射
	glGenTextures(1, &texture); // 创建纹理 
	// 使用来自位图数据生成的典型纹理 
	glBindTexture(GL_TEXTURE_2D, texture); 


	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,Texture.cols,Texture.cols,
					0,GL_RGB,GL_UNSIGNED_BYTE,Texture.data);//指定纹理图像
	int errn = glGetError();
	printf("errn = %d\n",errn);


	glBindTexture(GL_TEXTURE_2D, texture); 
	glEnable(GL_TEXTURE_2D); 

	glColor3f(1.0,1.0,0.0); 
#if 1
	glBegin(GL_QUADS); 
	//glBegin(GL_POLYGON);
		glTexCoord2f(0.0,0.0);
		glVertex3fv(vertex[0]);
		glTexCoord2f(0.0,1.0);
		glVertex3fv(vertex[1]);
		glTexCoord2f(1.0,1.0);
		glVertex3fv(vertex[2]);
		glTexCoord2f(1.0,0.0);
		glVertex3fv(vertex[3]);
	glEnd();
#endif

#if 0	
	glBegin(GL_QUADS); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);//左下角
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f); // 右下角
	    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 0.5f, -0.5f);// 右上角
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, 0.5f, -0.5f);// 左上角
		glEnd();
   /* glColor3f(1.0,1.0,0.0);*/
	//glBegin(GL_QUADS);
		//glVertex3fv(vertex[0]);
		//glVertex3fv(vertex[1]);
		//glVertex3fv(vertex[2]);
		//glVertex3fv(vertex[3]);
	//glEnd();

#endif

	//glFlush();

	//glDrawPixels(Texture.cols,Texture.rows,GL_BGR_EXT,GL_UNSIGNED_BYTE,Texture.data);
    glutSwapBuffers();
}

void glInit(){
	glClearColor(0.0,0.0,0.0,0.0);	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0,4.0,-4.0,4.0,-4.0,4.0);//正交视域体
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

}

void Display(){
	glInit();
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
}

int main(int argc,char ** argv ){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glEnable(GL_DEPTH_TEST);


	glutCreateWindow("FileName");
	glutDisplayFunc(Display);
	glutMainLoop();
return 0;
}
