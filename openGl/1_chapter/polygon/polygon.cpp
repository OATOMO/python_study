#include <GL/glut.h>
#include <stdio.h>
//#include "GL/freeglut.h"
//#include "GL/gl.h"

void display(){
	glClear(GL_COLOR_BUFFER_BIT);//清除背景

	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	glFlush();
}
void init(){
	glClearColor(0.0,0.0,0.0,0.0);	//清除背景的颜色
	glColor3f(1.0,1.0,1.0);			//绘制颜色

	glMatrixMode(GL_PROJECTION);	//指定控制的矩阵,(本例为投影矩阵)
	glLoadIdentity();				//将矩阵设为单位矩阵
	gluOrtho2D(-1.0,-1.0,-1.0,-1.0);//投影的范围
}

int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	//显示模式
	glutInitWindowSize(500,500);					//窗口大小
	glutInitWindowPosition(0,0);					//窗口对于屏幕在左上角的位置
	glutCreateWindow("polygon");					//创建窗口
	glutDisplayFunc(display);						//注册显示回调函数
	init();

	const char* version = (const char *)glGetString(GL_VERSION);
	printf("openGL version %s\n",version);

	glutMainLoop();
}
