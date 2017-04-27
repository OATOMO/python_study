#!/usr/bin/python3
#------------------------------------------
		#		loop		#
#-----------------input()------------------
#messages = input("input name:")
#print (messages)
#------------------------------------------
#num = input("input a zheng num:")
#num = int(num)			#用int()将字符串转为整型
#
#if num%2 == 0:
#	print (True)
#else :
#	print (False)
#------------------------------------------
		#	while	#
#------------------------------------------
#for循环用于针对集合中的每个元素都一个代码块，而while循环不断地运行，直到指定的条件不满足为止。
#num = input("input a number:")
#num = int(num)
#while num < 5:
#	num = int(input('continue:'))
#------------------------------------------
#num = 0
#while num < 5:
#	print(str(num))
#	if num == 2:
#		break				#用break来终止循环
#	num += 1				#continue类似
#------------------------------------------
names = ['lz','atom','lz','tom','lz']
while 'lz' in names:
	names.remove('lz')
print (names)


	
	



