#!/usr/bin/python3
#--------------------------------------------
        #   function    #
#--------------------------------------------
#函数是带名字的代码块，用于完成具体的工作
#--------------------------------------------
# def greet_user():
#     """显示简单的问候语句"""
#     print ("Hello !")

# greet_user()
#--------------------------------------------
# def greet_user(username):
#     """显示简单的问候语句"""
#     print ("hello ," + username.title())

# greet_user("tom")
#--------------------------------------------
#关键字形参,名与值对应,
# def greet_user(username,info):
#     """显示简单的问候语句"""
#     print ("hello" + username + "," + info)

# greet_user(info = 'man',username = 'tom')
#--------------------------------------------
#默认值,简化调用,也能提示经典用法
# def greet_user(username,info = 'man'):
#     """显示简单的问候语句"""
#     print ("hello" + username + "," + info)

# greet_user(username = 'tom')
#--------------------------------------------
#返回值的使用
# def get_name(first_name,last_name):
#     full_name = first_name + last_name
#     return full_name.title()

# name = get_name('a','tom')
# print ('my name is: ' + name)
#--------------------------------------------
#返回字典
# def get_name(first_name,info):
#     person = {'name':first_name.title(),'info':info}
#     return person

# person = get_name('atom','man')
# print ("\nname :" + person['name'] + 
#         "\ntype:" + person['info'])
#--------------------------------------------
#传递列表
# def greet_user(names):
#     """向列表中每位用户问好"""
#     for name in names:
#         msg = "Hello ," + name.title()
#         print (msg)

# users = ['Atom','lz','tom']
# greet_user(users)
#--------------------------------------------
#函数来修改列表
# def print_name(unprinted,completed):
#     while unprinted:
#         current = unprinted.pop()
#         print ('name' + current)

#         completed.append(current)

# def show_name(completed):
#     print ("-----show-----")
#     for name in completed:
#         print (name)

# unprinted = ['atom','lz','tom']
# completed = []

# print_name(unprinted,completed)
# show_name(completed)
# print ("-------------")
# print (unprinted)
# print (completed)
#--------------------------------------------
# def print_name(unprinted,completed):
#     while unprinted:
#         current = unprinted.pop()
#         print ('name' + current)

#         completed.append(current)

# def show_name(completed):
#     print ("-----show-----")
#     for name in completed:
#         print (name)

# unprinted = ['atom','lz','tom']
# completed = []

# print_name(unprinted[:],completed)  #用切片传递的是副本,不会改变列表本身
# show_name(completed)
# print ("-------------")
# print (unprinted)
# print (completed)
#--------------------------------------------
# def make_pizza(*topings):  #创建一个元组,将可变参数全放入
#     for pizza in topings:
#         print ("-" + pizza)

# make_pizza('pepper')
# make_pizza('atom','lz')
#--------------------------------------------
#--------------------------------------------
#--------------------------------------------
#--------------------------------------------



