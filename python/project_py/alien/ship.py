#!/usr/bin/python3
#---------------------------------
import pygame

class Ship():
    """
    创建飞机的类
    """
    def __init__(self,screen):
        """
        初始化飞机的坐标并设置初始位置
        """
        self.screen = screen
        self.moving_right = False   #移动标志
        self.moving_left  = False
        #加载飞船图像获取其外接矩形
        self.image = pygame.image.load('./images/ship.bmp')
        self.rect  = self.image.get_rect()      #图片rect矩形对象
        self.screen_rect = screen.get_rect()    #屏幕矩形对象

        #将每艏飞船放在底部中央
        self.rect.centerx = self.screen_rect.centerx    #矫正到中心
        self.rect.bottom  = self.screen_rect.bottom     #矫正到底部

    def blitme(self):
        """
        在指定位置绘制飞船
        """
        self.screen.blit(self.image,self.rect)

    def updata(self):
        "根据标志来移动位置"
        if self.moving_right:
            self.rect.centerx += 1
        elif self.moving_left:
            self.rect.centerx -= 1
