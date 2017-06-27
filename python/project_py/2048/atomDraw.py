#!/usr/bin/python
#coding=utf-8

import math

class Point(object):
    def __init__(self,x,y):
        self.x = x;
        self.y = y;
    def __sub__(self,other):
        return Point(self.x-other.x,self.y-other.y)
    def __add__(self,other):
        return Point(self.x+other.x,self.y+other.y)

    @property
    def xy(self):
        return (self.x,self.y)
    def __str__(self):
        return "x={0},y={1}".format(self.x,self.y)
    def __repr__(self):
        return str(self,xy)

    @staticmethod
    def dist(a,b):
        return math.sqrt((a.x-b.x)**2 + (a.y-b.y)**2)

from abc import ABCMeta,abstractmethod

#基类多边形
class Polygon(object):
    #用来生成抽象基础类的元类,由她生成的类可以被直接继承
    __metaclass__ = ABCMeta
    def __init__(self,points_list,**Kwargs):
        # **Kwargs是一个关键字参数,它是一个字典
        for point in points_list:
            assert isinstance(point,Point),"input must be Point type"
            self.points = points_list[:]
            self.points.append(points_list[0])#使矩形闭合
            #获得关键字的键值
            self.color=Kwargs.get('color','#000000')

    #遍历一个多边行的所有点
    def drawPoints(self):
        points_xy = []
        for point in self.points:
            points_xy.append(point.xy)
        print points_xy

        return tuple(points_xy)
    @abstractmethod
    def area(self):
        raise("not implement")

    def __lt__(self,other):
        assert isinstance(other,Polygon)
        return self.area<other.area

#子类矩形
class RectAngle(Polygon):
    def __init__(self,startPoint,w,h,**Kwargs):
        self._w = w
        self._h = h
        Polygon.__init__(self,[startPoint,startPoint+Point(w,0),startPoint+Point(w,h),startPoint+Point(0,h)],**Kwargs)

    def area(self):
        return self._w * self._h

#子类圆形
class CircleAngle(Polygon):
    def __init__(self,center_xy,r,accuracy,**Kwargs):
        self.center_xy = center_xy
        self.r = r
        self.accuracy = accuracy
        points_xy = []
        for i in accuracy:
            #jiao = float(i)/accuracy*2*math.pi
            #x1 = x+r*math.cos(jiao)
            #y1 = y+r*math.sin(jiao)
