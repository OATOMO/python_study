#include <GL/glut.h>
//#include "GL/freeglut.h"
//#include "GL/gl.h"

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	//glColor3i(0,250,0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.5,-0.5);
		glVertex2f(-0.5,0.5);
		glVertex2f(0.5,0.5);
		glVertex2f(0.5,-0.5);
	glEnd();
	glFlush();
}

int main(int argc,char ** argv){
	glutInit(&argc,argv);
	glutCreateWindow("polygon");
	glutDisplayFunc(display);
	glutMainLoop();
}
