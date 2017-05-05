#!/usr/bin/python3
#---------------------------------------
import pygame
from pygame.sprite import Sprite

class Bullet(Sprite):
    """
    一个对飞船发射子弹进行管理的累
    """
    def __init__(self,ai_settings,screen,ship):
        """
        在飞船所在地方创建一个子弹
        """
        super(Bullet,self).__init__()
        self.screen = screen

        #在（0,0）处创建一个子弹的矩形
        #先在0,0处创建，之后再移动
        self.rect = pygame.Rect(0,0,
            ai_settings.bullet_width,ai_settings.bullet_height)
        self.rect.centerx = ship.rect.centerx
        self.rect.top = ship.rect.top

        #存储用小数表示的子弹位置
        self.y = float(self.rect.y)
        
        self.color = ai_settings.bullet_color
        self.speed_factor = ai_settings.bullet_speed_factor

    def update(self):
        """
        向上移动
        """
        #更新位置的小数值
        self.y -= self.speed_factor
        #更新位置
        self.rect.y = self.y

    def draw_bullets(self):
        """
        在屏幕上绘制
        """
        pygame.draw.rect(self.screen,self.color,self.rect)

