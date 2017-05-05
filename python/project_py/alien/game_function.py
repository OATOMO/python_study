import sys
import pygame
from bullet import Bullet

def check_keydown_events(event,ai_settings,screen,ship,bullets):
    "检测按下事件"
    if event.key == pygame.K_RIGHT:
        ship.moving_right = True
    elif event.key == pygame.K_LEFT:
        ship.moving_left = True
    elif event.key == pygame.K_UP:
        ship.moving_up = True
    elif event.key == pygame.K_DOWN:
        ship.moving_down = True
    elif.event.key == pygame.K_SPACE:
        #创建一颗子弹
        new_bullet = Bullte(ai_settings,screen,ship)
        bullets.add(new_bullet)

def check_keyup_events(event,ai_settings,screen,ship,bullets):
    "检查松开事件"
    if event.key == pygame.K_RIGHT:
        ship.moving_right = False
    elif event.key == pygame.K_LEFT:
        ship.moving_left = False
    elif event.key == pygame.K_UP:
        ship.moving_up = False
    elif event.key == pygame.K_DOWN:
        ship.moving_down = False

def check_events(ai_settings,screen,ship,bullets):
    """监视游戏的鼠标和键盘"""
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()

        elif event.type == pygame.KEYDOWN:
            check_keydown_events(event,ai_settings,screen,ship,bullets)

        elif event.type == pygame.KEYUP:
            check_keyup_events(event,ship);

def updata_screen(ai_settings,screen,ship,bullets):
    """
    更新屏幕
    """
    #每次循环都重绘屏幕
    screen.fill(ai_settings.bg_color)
    #在飞船和外星人后面重绘所有子弹
    for bullet in bullets.sprites():
        bullet.draw_bulltes()
    ship.blitme()
    #让最近绘制的屏幕可见
    pygame.display.flip()
