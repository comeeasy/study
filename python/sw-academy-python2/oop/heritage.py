# 파이썬에서는 단일 상속만을 지원한다
'''
syntax :
    class 클래스명(부모클래스명) :
        ...
'''

class Parent :
    def __init__(self, family_name) :
        self.__family_name = family_name
        print("Parent 클래스의 __init__")
        
    @property
    def family_name(self) :
        return self.__family_name
    
# Parent class 상속
class Child(Parent) :
    def __init__(self, first_name, last_name) :
        Parent.__init__(self, last_name)
        # super().__init__(last_name)
        self.__first_name = first_name
        print("Child 클래스의 __init__")
        
