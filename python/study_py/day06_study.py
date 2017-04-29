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
#---------------------------------------------
#---------------------------------------------
