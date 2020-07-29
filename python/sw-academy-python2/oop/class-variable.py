'''
class 클래스명 :
    클래스변수 = 값
    ...
    
와 같이 정의

클래스명.클래스변수
와 같이 접근
'''

class Person :
    count = 0
    
    def __init__(self, name, age) :
        self.__name = name      
        self.__age  = age
        print(self.name, "이 생성")
        Person.count += 1
    
    def __del__(self) :
        print(self.name, "이 제거")
        
    def to_str(self) :
        return "{0}\t{1}".format(self.name, self.age)
    
    @property
    def name(self) :
        return self.__name
    
    @property
    def age(self) :
        return self.__age
    
    @age.setter
    def age(self, age) :
        if age < 0 :
            raise TypeError("나이는 음수가 아니야")
        self.__age = age
        
people = [
    Person("홍길동", 20),
    Person("이순신", 45),
    Person("강감찬", 35)
]

print("Person 클래스의 개수는 {0}개이다".format(Person.count))