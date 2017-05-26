#!/usr/bin/python3
#-----------------------------------
    #   a alien invasion game
#-----------------------------------
import pygame

from settings import Settings
from ship import Ship
from pygame.sprite import Group
from alien import Alien
from game_stats import GameStats
import game_function as gf


def run_game():
    """
    初始化游戏并创建对象
    """
    pygame.init() #初始化背景设置
    ai_settings = Settings()
    screen = pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))    #创建一个名为screen的窗口
    
    
    ship = Ship(ai_settings,screen) #飞船实例
    stats = GameStats(ai_settings)
    bullets = Group()               #管理子弹实例的组
    aliens = Group()                #管理外星人实例的组

    #创建外星人群
    gf.create_fleet(ai_settings,screen,ship,aliens)
    #开始游戏的主循环
    while True:
        gf.check_events(ai_settings,screen,ship,bullets)
        ship.updata()
        gf.update_bullets(ai_settings,screen,ship,aliens,bullets)
        gf.update_aliens(ai_settings,stats,screen,ship,aliens,bullets)
        gf.updata_screen(ai_settings,screen,ship,bullets,aliens)


run_game()
#-----------------------------------
