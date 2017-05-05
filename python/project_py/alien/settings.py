#!/usr/bin/python3
#----------------------------------
    #   用于设置的一个类 #
#----------------------------------
class Settings():
    """
    存储<外星人入侵>的所有设置类
    """

    def __init__(self):
        """
        屏幕设置
        """
        self.screen_width = 1000
        self.screen_height= 600
        self.bg_color = (230,230,230)

        #飞船的速度
        self.ship_speed_factor = 1.5

        #子弹
        self.bullet_speed_factor = 1
        self.bullet_width = 3
        self.bullet_height = 15
        self.bullet_color = (60,60,60)
        self.bullets_allowed = 3 #最多子弹数
