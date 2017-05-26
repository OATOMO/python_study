#!/usr/bin/python3


import sys
from PyQt5.QtWidgets import QApplication,QWidget

class myform(QWidget):
    def __init__(self):
        super().__init__()  #调用父类QWidget的构造函数，这句很重要
        self.setWindowTitle('hello qt')
        self.resize(400,300)

if __name__=='__main__':
    app = QApplication(sys.argv)
    w = myform()    
    w.show()

app.exec_()


