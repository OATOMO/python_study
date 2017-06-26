#include "OpenGLWindow.hpp"
#include <QCoreApplication>  
#include <QPainter>  
#include <QOpenGLContext>  
#include <QOpenGLPaintDevice>  
#include <QWindow>

OpenGLWindow::OpenGLWindow(QWindow *parent)
		    : QWindow(parent)
			, m_update_pending(false)
			, m_animating(false)
			, m_context(0)
			, m_device(0)
{
			setSurfaceType(QWindow::OpenGLSurface);
}
