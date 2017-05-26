#!/usr/bin/python3
#------------------------------------------
#
#有bug，会抓到错误的url`
#
import re
from urllib import request
from urllib.request import urlopen
import urllib
from tqdm import tqdm 


imgurl = "http://erolord.com/view.php?g=3&d=2199921&m=23"
imgurl = "http://erolord.com/images/219/2199921/1.jpg"
imgurl = "http://erolord.com/images/219/2197586/18.jpg"
urllib.request.urlretrieve(imgurl,"./1.jpg")

#html = urlopen("http://www.erolord.com/view.php?g=10&d=2197586&m=29")
print (html)

