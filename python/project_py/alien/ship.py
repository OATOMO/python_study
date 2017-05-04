#!/usr/bin/python3
#---------------------------------
import pygame

class Ship():
    """
    创建飞机的类
    """
    def __init__(self,ai_settings,screen):
        """
        初始化飞机的坐标并设置初始位置
        """
        self.screen = screen
        self.ai_settings = ai_settings
        self.moving_right = False   #移动标志
        self.moving_left  = False
        self.moving_up    = False
        self.moving_down  = False
        #加载飞船图像获取其外接矩形
        self.image = pygame.image.load('./images/ship.bmp')
        self.rect  = self.image.get_rect()      #图片rect矩形对象
        self.screen_rect = screen.get_rect()    #屏幕矩形对象

        #将每艏飞船放在底部中央
        self.rect.centerx = self.screen_rect.centerx    #矫正到中心
        self.rect.bottom  = self.screen_rect.bottom     #矫正到底部


        self.center = float(self.rect.centerx)
        self.bottomh = float(self.rect.centery)

    def blitme(self):
        """
        在指定位置绘制飞船
        """
        self.screen.blit(self.image,self.rect)

    def updata(self):
        "根据标志来移动位置"
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.center += self.ai_settings.ship_speed_factor
        elif self.moving_left and self.rect.left > self.screen_rect.left:
            self.center -= self.ai_settings.ship_speed_factor
        elif self.moving_up :
            self.bottomh -= self.ai_settings.ship_speed_factor
        elif self.moving_down :
            self.bottomh += self.ai_settings.ship_speed_factor

        self.rect.centerx = self.center
        self.rect.centery = self.bottomh
