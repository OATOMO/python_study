#!/usr/bin/python3
#---------------------------------
from urllib.request import urlopen
from urllib.error import HTTPError
from bs4 import BeautifulSoup 

# url_link = "https://github.com/REMitchell/python-scraping"


#---------------------------------
#一个用不同字体写小说的网站
url_link = "http://www.pythonscraping.com/pages/warandpeace.html"
#---------------------------------
#dota2贴吧一个帖子
#url_link = "https://tieba.baidu.com/p/5103950523i" 
#---------------------------------



#---------------------------------
#被BeautifulSoup分解出来的标签
# html → <html><head>...</head><body>...</body></html>
# — head → <head><title>A Useful Page<title></head>
#---- — title → <title>A Useful Page</title>
# — body → <body><h1>An Int...</h1><div>Lorem ip...</div></body>
#----— h1 → <h1>An Interesting Title</h1>
#----— div → <div>Lorem Ipsum dolor...</div>
#---------------------------------
# html = urlopen("https://github.com/REMitchell/python-scraping")
# bs_obj = BeautifulSoup(html.read(),"xml")
# #bs_obj = bs(html.read())
# print (bs_obj.h1)
#---------------------------------
def getTitle(url):
    try:
        html = urlopen(url)
    except HTTPError as e:
        return None
    try:
        bs_obj = BeautifulSoup(html.read(),"xml")
        title = bs_obj.body.h1
    except Attribute as e:
        return None
    return title

title = getTitle(url_link)
if title == None:
    print("Title could not be found")
else:
    print(title)
#---------------------------------
