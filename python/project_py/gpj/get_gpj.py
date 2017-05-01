#!/usr/bin/python3
#------------------------------------------
import re
from urllib import request
import urllib

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
    res = r'https://.+\.jpg'
    res_c = re.compile(res)
    jpg_url_list = re.findall(res_c,html)
    print (jpg_url_list)
    for imgurl in jpg_url_list:
        urllib.request.urlretrieve(imgurl,"./1.jpg")

# print (getHtml(url_dota))
page_dota = getHtml(url_dota).decode('utf-8')
getJpg(page_dota)


