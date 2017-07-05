#!/usr/bin/python
#coding=utf-8
# app = wx.App()
# frame = wx.Frame(None,-1,title='wx__test.py',pos = (500,500),size = (200,200))
# frame.Show()
# app.MainLoop()

import wx
from atomDraw import *

class Example(wx.Frame):
    #"""继承自Frame"""
    def __init__(self,title,shapes):
        super(Example,self).__init__(None,title = title,size=(600,400))
        #绑定渲染窗口动作到OnPaint
        #这样当resize窗口,会重新调用该函数
        self.shapes = shapes
        self.Bind(wx.EVT_PAINT,self.OnPaint)

        self.Centre()
        self.Show()

    def OnPaint(self,e):
        #画一条直线,参数为起始点的x,y,终点的x,y
        dc = wx.PaintDC(self)
        for shape in self.shapes:
            dc.SetPen(wx.Pen(shape.color))
            dc.DrawLines(shape.drawPoints())

#----end class Exmple
if __name__ == "__main__":
    prepare_draws=[]
    start_p = Point(50,60)
    a=RectAngle(start_p,100,80,color='#ff00ee')
    prepare_draws.append(a)

    start_p = Point(40,30)
    a=RectAngle(start_p,60,20,color='#00f0ee')
    prepare_draws.append(a)


    start_p = Point(50,50)
    a = CircleAngle(start_p,40,40,color='#00f0ee') 
    prepare_draws.append(a)

    for shape in prepare_draws:
        print shape.area()

    app = wx.App()
    Example("Shapes",prepare_draws)
    app.MainLoop()


