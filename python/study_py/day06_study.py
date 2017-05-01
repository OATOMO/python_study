#!/usr/bin/python3
#---------------------------------------------
       #    file and abnormal
#---------------------------------------------
filename = './pi_digit.txt'
#with表示在文件不需要时自动关闭
#用open打开一个文件
# with open('pi_digit.txt') as file_object:
#     contents = file_object.read()
#     print(contents.rstrip())  #rstrip()删除末尾空行
#---------------------------------------------
# with open('pi_digit.txt') as file_object:
#     for line in file_object:        #逐行读取
#         print(line.rstrip())
#---------------------------------------------
# with open(filename) as file_object:
#     lines = file_object.readlines()

# for line in lines:
#     print (line.rstrip())
#---------------------------------------------
# with open(filename) as file_object:
#     lines = file_object.readlines()

# pi_string = ''
# for line in lines:
#     pi_string += line.rstrip().strip()

# print (pi_string)
# print (len(pi_string))
#---------------------------------------------
#'w':写  'r':读  'a':附加  'r+':能够读取和写入
# with open(filename,'w') as file_object: #以写的方式打开文件
#     file_object.write("i Love programming.")
#---------------------------------------------
        #   except  #
# try:
#     print (5/0)
# except ZeroDivisionError:
#     print ("you can't divide by zero!")
#---------------------------------------------
#用来处理找不到文件的异常
# try:
#     with open('yom.txt') as file_object:
#         contents = file_object.read()
# except FileNotFoundError:
#     msg = 'Sorry,the file' " does not exis."
#     print(msg)
#---------------------------------------------
# filename = 'day04_study.py'
# try:
#     with open(filename) as file_obj:
#         contents = file_obj.read()
# except FileNotFoundError:
#     msg = 'Sorry,the file ' + filename + 'does not exist.'
#     print (msg)
# else:
#     words = contents.split() #将字符串切分成单词列表
#     num_words = len(words)
#     print("the file " + filename + "has about " + str(num_words) + "words.")
#---------------------------------------------
        #   数据存储json    #
#---------------------------------------------
#用json.dump()来存储数据
# import json
# numbers = [1,2,3,4,5,6,7]

# filename = 'numbers.json'
# with open(filename,'w') as f_obj:
#     json.dump(numbers,f_obj)
#---------------------------------------------
#用json.load()来取出数据
import json

filename = 'numbers.json'
with open(filename) as f_obj:
    numbers = json.load(f_obj)

print (numbers)
#---------------------------------------------
#---------------------------------------------


