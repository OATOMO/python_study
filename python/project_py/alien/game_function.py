import sys
import pygame
from bullet import Bullet
import settings
from alien import Alien
from time  import sleep

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


def update_bullets(ai_settings,screen,ship,aliens,bullets):
    """
    更新子弹位置,并删除以消失的子弹
    """
    #更新子弹位置
    bullets.update()
        #删除以出屏幕的子弹
    for bullet in bullets.copy():
        if bullet.rect.bottom <= 0:
            bullets.remove(bullet)
    
    check_bullet_alien_collisons(ai_settings,screen,ship,aliens,bullets)

def check_bullet_alien_collisons(ai_settings,screen,ship,aliens,bullets):
    #检测是否有子弹碰到了外星人
    collisions = pygame.sprite.groupcollide(bullets,aliens,False,True)
    if len(aliens) == 0:
        bullets.empty()
        create_fleet(ai_settings,screen,ship,aliens)


def fire_bullet(ai_settings,screen,ship,bullets):
        #如果子弹没到上限,就创建一颗子弹
        if len(bullets) <= ai_settings.bullets_allowed:
            new_bullet = Bullet(ai_settings,screen,ship)
            bullets.add(new_bullet)


def get_number_aliens_x(ai_settings,alien_width):
    """并计算一行可容纳多少个外星人"""
    available_space_x = ai_settings.screen_width - (alien_width*2)
    number_aliens_x = int(available_space_x / (alien_width*2))
    return number_aliens_x

def get_number_rows(ai_settings,ship_height,alien_height):
    """计算创建多少列外星人"""
    available_space_y = ai_settings.screen_height - (3*alien_height) - ship_height
    number_rows = int(available_space_y / (2*alien_height))
    return number_rows

def create_alien(ai_settings,screen,aliens,alien_number,row_number):
    alien = Alien(ai_settings,screen)
    alien_width = alien.rect.width
    alien_height = alien.rect.height
    alien.x = alien_width + ((2 * alien_width) * alien_number)
    alien.y = alien_height + ((2 * alien_height) * row_number)
    alien.rect.x = alien.x
    alien.rect.y = alien.y
    aliens.add(alien)


def create_fleet(ai_settings,screen,ship,aliens):
    """创建外星人群"""
    #创建一个外星人,并计算一行可容纳多少个外星人
    alien = Alien(ai_settings,screen)
    numbers_aliens_x = get_number_aliens_x(ai_settings,alien.rect.width)
    numbers_rows = get_number_rows(ai_settings,ship.rect.height,alien.rect.height)


    for row_number in range(numbers_rows):
        #创建第一行外星人
        for alien_number in range(numbers_aliens_x):
            create_alien(ai_settings,screen,aliens,alien_number,row_number)
            #print (range(numbers_rows))
            
def check_fleet_edges(ai_settings,aliens):
    """有外星人达到边缘时,采取的措施"""
    for alien in aliens.sprites():
        if alien.check_edges():
            change_fleet_direction(ai_settings,aliens)
            break

def change_fleet_direction(ai_settings,aliens):
    """将整群外星人下移"""
    for alien in aliens.sprites():
        alien.rect.y += ai_settings.fleet_drop_speed
    ai_settings.fleet_direction *= -1

def ship_hit(ai_settings,stats,screen,ship,aliens,bullets):
    """响应被外星人撞到的飞船"""
    stats.ships_left -= 1

    #清空外星人和子弹列表
    aliens.empty()
    bullets.empty()

    #创建外星人并将飞船移到屏幕中心
    create_fleet(ai_settings,screen,ship,aliens)
    ship.center_ship()

    #暂停
    sleep(0.5)


def check_aliens_bottom(ai_settings,stats,screen,ship,aliens,bullets):
    """检查外星人是否到啦低端"""
    screen_rect = screen.get_rect()
    for alien in aliens.sprites():
        if alien.rect.bottom >= screen_rect.bottom:
            ship_hit(ai_settings,stats,screen,ship,aliens,bullets)
            break

def update_aliens(ai_settings,stats,screen,ship,aliens,bullets):
    """更新所以外星人的位置"""
    check_fleet_edges(ai_settings,aliens)
    aliens.update() #对Group()调用函数对每个成员都调用一次
    #检测外星人也飞船之间的碰撞
    check_aliens_bottom(ai_settings,stats,screen,ship,aliens,bullets)
    if pygame.sprite.spritecollideany(ship,aliens):
        ship_hit(ai_settings,stats,screen,ship,aliens,bullets)
        # sys.exit()

