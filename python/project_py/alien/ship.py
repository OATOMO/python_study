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

        #加载飞船图像获取其外接矩形
        self.image = pygame.image.load('./images/ship.bmp')
        self.rect  = self.image.get_rect()
        self.screen_rect = screen.get_rect()

        #将每艏飞船放在底部中央
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom  = self.screen_rect.bottom

    def blitme(self):
        """
        在指定位置绘制飞船
        """
        self.screen.blit(self.image,self.rect)

