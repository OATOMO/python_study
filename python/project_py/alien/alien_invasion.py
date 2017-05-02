#!/usr/bin/python3
#-----------------------------------
    #   a alien invasion game
#-----------------------------------
import sys  #用来关闭游戏
import pygame

from settings import Settings

def run_game():
    """
    初始化游戏并创建对象
    """
    pygame.init() #初始化背景设置
    ai_settings = Settings()
    screen = pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))    #创建一个名为screen的窗口

    #开始游戏的主循环
    while True:
        #监视游戏的鼠标和键盘
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()

        #每次循环都重绘屏幕
        screen.fill(ai_settings.bg_color)
        #让最近绘制的屏幕可见
        pygame.display.flip()

run_game()
#-----------------------------------

