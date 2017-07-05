#ifndef __QOPENGLWINDOW_H
#define __QOPENGLWINDOW_H


#include <QWindow>
//#include <QOpenGlFunctions>
#include <QOpenGLExtraFunctions>
#include <QBackingStore>

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

class OpenGLWindow:public QWindow,protected QOpenGLFunctions{
	Q_OBJECT
public:
	explicit OpenGLWindow(QWindow * p = 0);

	virtual void render(QPainter *);
	virtual void render();

	virtual void initialize();

	void setAnimating(bool animating);

public slots:
	void renderLater();
    void renderNow();
protected:
    bool event(QEvent *event);

    void exposeEvent(QExposeEvent *event);
private:
    bool m_update_pending;
    bool m_animating;

    QOpenGLContext *m_context;
	QOpenGLPaintDevice *m_device;
}; 

#endif __QOPENGLWINDOW_H
