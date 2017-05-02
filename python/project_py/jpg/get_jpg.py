#!/usr/bin/python3
#------------------------------------------
#
#有bug，会抓到错误的url`
#
import re
from urllib import request
import urllib
from tqdm import tqdm 

url_dota = 'https://tieba.baidu.com/p/5097345368'

def getHtml(url):
    """
    获取url
    """
    page = request.urlopen(url)
    html = page.read()
    return html

def getJpg(html):
    """
    获取图像
    """
    res = """<img.*?src="(.*?)".*?>"""
    # res = r'src="https://\w+\.(jpg|gif|png|jpeg|bmp)"'
    # res = r"(\s+?http://)?(\d*\.(jpg|gif|png|jpeg|bmp))"
    res_c = re.compile(res)
    jpg_url_list = re.findall(res_c,html)
    print (jpg_url_list)
    for imgurl in tqdm(jpg_url_list):
        urllib.request.urlretrieve(imgurl,"./1.jpg")

# print (getHtml(url_dota))
page_dota = getHtml(url_dota).decode('utf-8')
getJpg(page_dota)


