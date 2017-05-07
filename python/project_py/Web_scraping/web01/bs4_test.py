#!/usr/bin/python3
#---------------------------------
from urllib.request import urlopen
from urllib.error import HTTPError
from bs4 import BeautifulSoup 
from tqdm import tqdm

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
# if title == None:
#     print("Title could not be found")
# else:
#     print(title)
#---------------------------------

html = urlopen(url_link)
bs_obj = BeautifulSoup(html.read(),"xml")
namelist = bs_obj.findAll("span",{"class":"green"})
for name in tqdm(namelist):
    #print (name)
    print (name.get_text()) #这样可以丢弃标签信息
# print (bs_obj.findAll({"h1","h2","h3","h4","h5","h6"}))

#---------------------------------
# 最重要的两函数find(),findAll().定义是:
#     findAll(tag,attributes,recursive,text,limit,keywords)
#     find(tag,attributes,recursive,text,keywords)
#     90%的时候都只使用前两个参数
#     第一个参数tag:
#         你可以传一个标签的名称或者是多个标签的列表:
#             例如下面代码将返回包含HTML文档中所有标题标签
#             findAll({"h1","h2","h3","h4","h5","h6"})
#     第二个参数attributes:
#         是用python字典封装的若干属性和属性值:
#             例如下面代码返回所有红色和绿色的span标签
#             findAll("span",{"class",{"green","red"}})
#     第三个参数recursive:
#         是一个布尔变量,代表是否递归查找子标签,findAll()默认是True
#     第四个参数text:
#         用来匹配标签的文本内容
#         findAll(text = "the prince")
#     第5个参数limit:
#         范围限制参数,显然只适用于findAll()方法,find()方法默认是1
#     第六个参数keywords:
#         可以让你选择那些具有指定属性的标签。例如：
#             allText = bsObj.findAll(id="text")
#             print(allText[0].get_text())
#---------------------------------
# • BeautifulSoup 对象
# 前面代码示例中的 bsObj

# • 标签 Tag 对象
# BeautifulSoup 对象通过 find 和 findAll，或者直接调用子标签获取的一列对象或单个

# 但是，这个库还有另外两种对象，虽然不常用，却应该了解一下。
# • NavigableString 对象
# 用来表示标签里的文字， 不是标签（有些函数可以操作和生成 NavigableString 对象，
# 而不是标签对象）。

# • Comment 对象
# 用来查找 HTML 文档的注释标签， <!-- 像这样 -->
#---------------------------------
