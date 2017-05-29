#!/usr/bin/python3

import sys
from PyQt5.QtWidgets import *
from erolord_kernel import *
import re

class erolordUi(QWidget):
    """下载器的UI"""
    def __init__(self,parent = None):
        self.path = ""

        super(erolordUi,self).__init__(parent)
         
        self.urlLabel = QLabel("Url")
        self.urlLineEdit = QLineEdit("Input Url")
        
        self.pathLineEdit = QLineEdit("Path")
        self.pathButton = QPushButton("Browse")

        self.downButton = QPushButton("&Down")
        self.downButton.setEnabled(False)
        self.cancelButton = QPushButton("&Cancel")

        #布局
        self.urlLayout = QHBoxLayout()
        self.pathLayout = QHBoxLayout()
        self.butLayout =QHBoxLayout()
        self.mainLayout = QVBoxLayout()
        
        self.urlLayout.addWidget(self.urlLabel)
        self.urlLayout.addWidget(self.urlLineEdit)

        self.pathLayout.addWidget(self.pathLineEdit)
        self.pathLayout.addWidget(self.pathButton)

        self.butLayout.addWidget(self.downButton)
        self.butLayout.addWidget(self.cancelButton)

        self.mainLayout.addLayout(self.urlLayout)
        self.mainLayout.addLayout(self.pathLayout)
        self.mainLayout.addLayout(self.butLayout)
        self.setLayout(self.mainLayout)

        #connect
        self.downButton.clicked.connect(self.run)
        self.cancelButton.clicked.connect(self.close)
        self.pathButton.clicked.connect(self.getPath)
        self.urlLineEdit.textChanged.connect(self.enButton)
    #internal fun
    def isUrl(self,url):
        """检测是否是url"""
        retval = re.findall(r"http://.*/.*",url) 
        if retval:
            return True
        else:
            return False

    #slot
    def run(self):
        """运行爬虫"""
        url_raw = self.urlLineEdit.text()
        # if self.isUrl(url_raw):
        getImage(getHtml(str(url_raw)),str(self.pathLineEdit.text()))
        print ()
        # else:
            # QMessageBox.warning(self,"Waring","url format error")

    def getPath(self):
        self.path = QFileDialog.getExistingDirectory(self,  
                                "choose path",  
                                "/") 
        self.pathLineEdit.setText(self.path)
        print (self.path)

    def enButton(self):
        if self.isUrl(self.urlLineEdit.text()):
            self.downButton.setEnabled(True)
        else:
            self.downButton.setEnabled(False)


if __name__ == "__main__":
    app = QApplication(sys.argv)
    ero = erolordUi()
    ero.show()
    sys.exit(app.exec_())
