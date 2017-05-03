#!/usr/bin/python3
#-----------------------------------
    #   a alien invasion game
#-----------------------------------
import pygame

from settings import Settings
from ship import Ship
import game_function as gf

def run_game():
    """
    初始化游戏并创建对象
    """
    pygame.init() #初始化背景设置
    ai_settings = Settings()
    screen = pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))    #创建一个名为screen的窗口

    ship = Ship(screen)
    #开始游戏的主循环
    while True:
        gf.check_event(ship)
        ship.updata()
        gf.updata_screen(ai_settings,screen,ship)

run_game()
#-----------------------------------
