# -*- coding: utf-8 -*-
# prac0.py

'''
국적을 출력하는 printNationality 
정적 메서드를 갖는 Korean 클래스를 정의하고
메서드를 호출하는 코드를 작성해봅시다.

@classmethod or
@staticmethod
를 decorate하여 사용
'''

class Korean :
    @staticmethod
    def printNationality() :
        print("대한민국\n대한민국")
        
Korean.printNationality()

