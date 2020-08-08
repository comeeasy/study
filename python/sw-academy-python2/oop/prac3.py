# -*- coding : utf-8 -*-
# prac3.py

'''
반지름 정보를 갖고, 원의 면적을 계산하는 
메서드를 갖는 Circle 클래스를 정의하고,
생성한 객체의 원의 면적을 출력하는 프로그램을 작성하십시오.

r = 2
'''

#from math import pi

pi = 3.14

class Circle :
    def __init__(self, radius) :
        self.__radius = radius
    
    @property
    def radius(self) :
        return self.__radius
    
    def cal_area(self) :
        return self.radius**2 * pi
    
c = Circle(2)
print("원의 면적: {0:.2f}".format(c.cal_area()))