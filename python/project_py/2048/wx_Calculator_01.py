#!/usr/bin/python
#coding=utf-8

import wx
from math import *

class CalcFram(wx.Frame):
    def __init__(self,title):
        super(CalcFram,self).__init__(None,title = title,size = (300,250))
        self.InitUI()
        self.Center()
        self.Show()

    def InitUI(self):
        vbox = wx.BoxSizer(wx.VERTICAL) #先定义一个BoxSizer,这个东西允许以行列放控件
        self.textprint = wx.TextCtrl(self,style=wx.TE_RIGHT) #先弄个文本框
        vbox.Add(self.textprint,flag=wx.EXPAND | wx.TOP | wx.BOTTOM,border=4)

        gridBox = wx.GridSizer(5,4,5,5)
                    #       rows|cols|vgap|hgap
        labels=['AC','DEL','PI','CLOSE','7','8','9','/','4','5','6','*','1','2','3','-','0','.','=','+']
        for label in labels:
            gridBox.Add(wx.Button(self,label=label),1,wx.EXPAND)
            
        vbox.Add(gridBox,proportion = 1,flag=wx.EXPAND)
        self.SetSizer(vbox)

if __name__ == '__main__':
    app = wx.App()
    CalcFram(title = 'Calculatior')
    app.MainLoop()


