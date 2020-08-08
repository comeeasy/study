# -*- cofing L utf-8 -*-
# prac4.py

'''
Shape를 부모 클래스로 Square 자식 클래스를 정의하는 코드를 작성하십시오.
Square 클래스는 length 필드를 가지며, 0을 반환하는 
Shape 클래스의 area 메서드를length * length 값을 
반환하는 메서드로 오버라이딩합니다.
'''

class Shape :
    def area(self) :
        return 0
    
class Square(Shape) :
    def __init__(self, length) :
        self.__length = length
       
    @property
    def length(self) :
        return self.__length    
        
    def area(self) :
        return self.length**2
    
s = Square(3)
print("정사각형의 면적: {0}".format(s.area()))
        