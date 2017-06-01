#!/usr/bin/python3
#codeing:utf-8

from PyQt5.QtWidgets import *
import re
import sys

class EroDownLoad(QDialog):
    """EROLORD下载器类"""
    def __init__(self,parent = None):
        """构造函数"""
        super(EroDownLoad,self).__init__(parent)
        self.setWindowTitle("<- EroLord Download ->")
        #url label
        self.res_Label = QLabel("url")
        self.res_Url = QLineEdit()
        #path label
        self.path_Label = QLabel("Path")
        self.path_LineEdit = QLineEdit()
        
        path_Button = QPushButton("Browse")
        downButton = QPushButton("Download")
        cancelButton = QPushButton("Cancel")
        
        #布局
        urlLayout  = QHBoxLayout()
        butLayout  = QHBoxLayout()
        mainLayout = QVBoxLayout()
        pathLayout = QHBoxLayout()

        urlLayout.addWidget(self.res_Label)    
        urlLayout.addWidget(self.res_Url) 

        pathLayout.addWidget(self.path_Label)
        pathLayout.addWidget(self.path_LineEdit)
        pathLayout.addWidget(path_Button)

        butLayout.addWidget(downButton)
        butLayout.addWidget(cancelButton)

        mainLayout.addLayout(urlLayout)
        mainLayout.addLayout(pathLayout)
        mainLayout.addLayout(butLayout)
        self.setLayout(mainLayout)
        #connect
        downButton.clicked.connect(self.run)
        cancelButton.clicked.connect(self.reject)
        path_Button.clicked.connect(self.browse)

    def run(self):
        """pass"""
        raw_url = self.res_Url.text().strip()
        if(re.findall(r'http',raw_url)):
            print(self.res_Url.text().strip()) 
        else:
            QMessageBox.warning(self,"Waring","url format Error",QMessageBox.Yes)
            self.res_Url.setFocus()   #错误时把焦点设为url Label

    def browse(self):
        """选择路径的槽"""
        file_path = QFileDialog.getExistingDirectory(self,"请选择模板保存路径...","./");  
        self.path_LineEdit.setText(file_path)

if __name__ =='__main__':
    app = QApplication(sys.argv)
    w = EroDownLoad()
    w.show()

    app.exec_()
        
