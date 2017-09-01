#ifndef MYCUBE_H
#define MYCUBE_H

#include <QTimer>
#include <QGLWidget>
#include <QWidget>
#include <cmath>

class myCube:public QGLWidget
{
	Q_OBJECT
public:
	myCube(QWidget * parent = 0);
	~myCube();

	QTimer clk;
	float m_x,m_y,m_z;
	GLuint textur;

protected:
	void initializeGL();
	void initWidget();
	void paintGL();
	void resizeGL(int width,int height);
	void loadGLTextures();
private slots:
	void updateWindow();

};

#endif // MYCUBE_H
