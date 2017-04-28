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
#names = ['lz','atom','lz','tom','lz']
#while 'lz' in names:
#	names.remove('lz')      #用while和remove来剔除多个重复项
#print (names)
#------------------------------------------
#users = {                      #字典中包含字典
#    'atom':{
#        'first':'A',
#        'last':'atom',
#        'love':'c'
#        },        
#
#    'lz':{
#        'first':'L',
#        'last':'z',
#        'love':'python'
#        }
#    }
#
#for user_name,user_info in users.items():
#    print ("\nuser:"+user_name)
#    full_name = user_info['first'] + user_info['last']
#    love = user_info['love']
#
#    print ('full name:'+full_name)
#    print ('love:'+love)
#------------------------------------
# responses = {}

# polling_active = True

# while polling_active:
#     name = input("\nWhat is your name?:")
#     response = input("Which mountain would you like to climb someday?")

#     responses[name] = response

#     repeat = input("Would you like to let respond ?(yes/no)")
#     if repeat == 'no':
#         polling_active = False
#     print("\n --Poll Results ---")
    
# for name,response in responses.items():
#     print(name + "would like to climb " + response + ".")
#-----------------------------------




 

	



