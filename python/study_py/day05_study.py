#!/usr/bin/python3
#--------------------------------------------
        #   class   #
#--------------------------------------------
class Dog():
    """创建一个类"""
    def __init__(self,name,age):
        """"初始化属性"""
        self.name = name
        self.age = age
        self.type = 'dog'  #设置默认初始值

    def sit(self):
        print(self.name.title() + "is now Sitting")

    def roll_over(self):
        print(self.name.title() + "rolled over")

#my_dog = Dog('willie',6)
#print ("May Dog's name is " + my_dog.name.title() + ".")
#print ("May dog's " + str(my_dog.age) + " years old.")
#--------------------------------------------
# my_dog = Dog('papa',1)
# my_dog.type = 'cat'     #直接修改初始值,也可以用方法修改
# print (my_dog.type)
#--------------------------------------------
        #   super   #
# class Papa(Dog):
#     def __init__(self,name,age):
#         super().__init__(name,age)

#     def look(self):
#         print(self.name +" look her.")
        
# papa = Papa('Papa',2)
# papa.look()
#--------------------------------------------
# from collections import OrderedDict #导入这个标准类
# #有序的字典类
# favorite_languages = OrderedDict()

# favorite_languages['tom'] = 'Python'
# favorite_languages['atom'] = 'c/c++'
# favorite_languages['lz'] = 'ass'

# for name,language in favorite_languages.items():
#     print (name + 'favorite language is:' + language)
#--------------------------------------------
# from random import randint    #生成随机数的类
# x = randint(1,6)
# print(str(x))
#--------------------------------------------

#--------------------------------------------
#--------------------------------------------
