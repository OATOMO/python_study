import sys
import pygame
from bullet import Bullet
import settings
from alien import Alien

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
    elif event.key == pygame.K_SPACE:
        fire_bullet(ai_settings,screen,ship,bullets)
    elif event.key == pygame.K_q:
        sys.exit()

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
            check_keyup_events(event,ai_settings,screen,ship,bullets);

def updata_screen(ai_settings,screen,ship,bullets,aliens):
    """
    更新屏幕
    """
    #每次循环都重绘屏幕
    screen.fill(ai_settings.bg_color)
    #在飞船和外星人后面重绘所有子弹
    for bullet in bullets.sprites():
        bullet.draw_bullets()
    ship.blitme()
    aliens.draw(screen)
    #让最近绘制的屏幕可见
    pygame.display.flip()


def update_bullets(bullets):
    """
    更新子弹位置,并删除以消失的子弹
    """
    #更新子弹位置
    bullets.update()
    #删除以出屏幕的子弹
    for bullet in bullets.copy():
        if bullet.rect.bottom <= 0:
            bullets.remove(bullet)
    print (len (bullets))
 

def fire_bullet(ai_settings,screen,ship,bullets):
        #如果子弹没到上限,就创建一颗子弹
        if len(bullets) <= ai_settings.bullets_allowed:
            new_bullet = Bullet(ai_settings,screen,ship)
            bullets.add(new_bullet)

def create_fleet(ai_settings,screen,aliens):
    """创建外星人群"""
    #创建一个外星人,并计算一行可容纳多少个外星人
    alien = Alien(ai_settings,screen)
    alien_width = alien.rect.width
    available_space_x = ai_settings.screen_width - (alien_width*2)
    number_aliens = int(available_space_x / (alien_width*2))

    #创建第一行外星人
    for alien_number in range(number_aliens):
        alien = Alien(ai_settings,screen)
        alien.x = alien_width + ((2 * alien_width) * alien_number)
        alien.rect.x = alien.x
        aliens.add(alien)