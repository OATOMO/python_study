#!/sur/bin/python3
#-----------------------------------
import pygame
from pygame.sprite import Sprite
#-----------------------------------
class Alien(Sprite):
    """
    表示单个外星人类
    """
    def __init__(self,ai_settings,screen):
        """初始化"""
        super(Alien,self).__init__()
        self.screen = screen
        self.ai_settings = ai_settings

        #加载外星人图像
        self.image = pygame.image.load("images/alien.bmp")
        self.rect = self.image.get_rect()

        #每个外星人初始位置都在左上角附近
        self.rect.x = self.rect.width
        self.rect.y = self.rect.height

        #存储外星人的准确坐标
        self.x = float(self.rect.x)

    def blitme(self):
        """绘制外星人"""
        self.screen.blit(self.image,self.rect)
#-----------------------------------
#-----------------------------------
