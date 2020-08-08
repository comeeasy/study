'''
Student Class
    - private 필드를 가지고 있음
    - 읽기 전용, name, gender의 property
    - 읽기, 쓰기 모두 가능한 height property
    - 특수 함수 __repr__ 에 대한 정의를 가짐
'''

# -*- coding: utf-8 -*-
# student-sorted.py

class Student :
    def __init__(self, name, gender, height) :
        self.__name   = name
        self.__gender = gender
        self.__height = height
    
    @property
    def name(self) :
        return self.__name
    
    @property
    def gender(self) :
        return self.__gender
    
    @property
    def height(self) :
        return self.__height
    
    @height.setter
    def height(self, height) :
        self.__height = height
        
    # 대부분의 객체를 표현할 때 많이 사용하는 repr = representation
    # __repr__ 를 __str__으로 바꾸어도 큰 차이는 없음
    def __repr__(self) :
        return "{0}(name: {1}, gender: {2}, height: {3})".format(self.__class__.__name__, \
            self.name, self.gender, self.height)

s1 = Student("홍길동", "남", 176.5)
print(s1)
# $ Student(name: 홍길동, gender: 남, height: 176.5) 

students = [
    Student("홍길동", "남", 176.5),
    Student("이순신", "남", 188.5),
    Student("유관순", "여", 158.4),
    Student("강감찬", "님", 182.2)
]

for student in students :
    print(student)
    
# 정렬은?
print("name으로 오름차순 정렬 후")
for student in sorted(students, key=lambda x: x.name, reverse=False) :
    print(student)
    
print("name으로 내림차순 정렬 후")
for student in sorted(students, key=lambda x: x.name, reverse=True) :
    print(student)