'''
class Person :
    pass

member = Person()

if isinstance(member, Person) :
    print("맞아")
'''    

'''
=> constructor method define
class 클래스명 :
    def __init__(self, 매개변수목록) :
        ...
        ...
        
=> destructor method define
class 클래스명 :
    ...
    
    def __del__(self) :
        ...
        ...
        
self 는 C++ 에서 this와 비슷한 역할
'''

class Person :
    def __init__(self, name, age) :
        self.name = name
        self.age = age
        print("{0} 객체가 생성되었습니다.".format(self.name))
        
    def __del__(self) :
        print("{0} 객체가 제거 되었습니다.".format(self.name))
        
member = Person("홍길동", 20)
print(dir(member))