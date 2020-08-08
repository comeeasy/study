# -*- coding : utf-8 -*-
# prac2.py

'''
name 프로퍼티를 가진 Student를 부모 클래스로 major 프로퍼티를 가진
GraduateStudent 자식 클래스를 정의하고 이 클래스의 객체를
다음과 같이 문자열로 출력하는 코드를 작성하십시오.
'''

class Student :
    def __init__(self, name) :
        self.__name = name
    
    @property
    def name(self) :
        return self.__name
    def __repr__(self) :
        return "이름: {0}".format(self.name)
    
class GraduateStudent(Student) :
    def __init__(self, name, major) :
        Student.__init__(self, name)
        self.__major = major
        
    @property
    def major(self) :
        return self.__major
    def __repr__(self) :
        return "이름: {0}, 전공: {1}".format(self.name, self.major)
    
s = Student("홍길동")
gs = GraduateStudent("이순신", "컴퓨터")

# print(dir(GraduateStudent))
print(s, gs, sep='\n')
    
