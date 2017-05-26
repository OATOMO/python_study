#!/usr/bin/python3
from urllib.request import urlopen
import urllib
from urllib.error import HTTPError
from bs4 import BeautifulSoup 
from tqdm import tqdm
import re
#coding=utf-8

url_1 = "http://erolord.com/image/2204367/"
url_2 = "http://erolord.com/view.php?g=2&d=2205069&m=21"
url_3 = "http://erolord.com/content/crossdressing/"
url_4 = "http://erolord.com/doujin/2199921/"
url_main = "http://erolord.com/doujin/2197586/"
erolord_url = ""
mark_sign = "******************************\n"
image_url_last = r"/view\.php\?g=\d+&d=\d+&m=\d+"
image_url_first = ""
#-----------------------------------------
url_link = url_main

def getHtml(url):
    try:
        html = urlopen(url)
        return html
    except HTTPError as e:
        print ("HTTP获取错误")
        return None
    #except SocketError as e:
    except ConnectionResetError as e:
        print ("reset connect")
        return None
def getbs4(html):
    try:
        bs_obj = BeautifulSoup(html.read(),"xml")
    except AttributeError as e:
        return None
    return bs_obj

def getTitle(bs_obj):
    title = bs_obj.body.h1
    return title

def cutIndex(str):
    """截取链接中的图片编号 """
    index = ""
    signe = 4
    start_i = 0
    last_i = 0
    while signe:
        if str[start_i] == "/":
            signe -= 1
            start_i += 1
        else: 
            start_i += 1
    last_i = start_i
    while str[last_i] != '.':
        last_i += 1
    return str[start_i:last_i]
    
def getImage(html):
    res_c = re.compile(image_url_last)
    image_url_last_list = res_c.findall(str(html.read()))

    for link_raw in tqdm(image_url_last_list):
        #拼接地址,再找到并拼接图片地址
       #  http://erolord.com/doujin/2199921/                #本子主地址
       #  /view.php?g=1&d=2199921&m=23                      #CSS层里面的图片页面地址
       #  http://www.erolord.com/view.php?g=10&d=2197586&m=29  #图片页面地址,里面有图片的链接
       #  /images/219/2197586/10.jpg                        #上一层隐藏的图片链接          
       #  http://erolord.com/images/219/2199921/1.jpg       #图片链接
        link_raw = "http://www.erolord.com"+link_raw
        jpg_html = getHtml(link_raw)
        jpg_raw_list = re.findall(r"/images/\d+/\d+/\d*\.jpg",str(jpg_html.read()))
        for image in jpg_raw_list:
            i = 0
            #下载图片
            urllib.request.urlretrieve( "http://erolord.com"+image,cutIndex(image) +".jpg")    
            #print ("http://erolord.com"+image)   

        print (jpg_raw_list)


def run():
    """运行爬虫"""
    html = getHtml(url_link)
    getImage(html)
    #bs_obj = getbs4(html)
    # print (getTitle(bs_obj))

# def getImage(bs_obj):
#     image_url_list = bs_obj.findAll("img",{"class":"mainimg"})
#     jpg_url_list = []
#     #print (image_url_list)
    
#     res = r"(http://.*jpg)"
#     res_c = re.compile(res)
#     while image_url_list:
#         link = image_url_list.pop()
#         jpg_url_list = res_c.findall(str(link))
#         #jpg_url_list = re.search(res,str(link)) 
#     print (jpg_url_list)


run()

