'''
class 클래스명 :
    @classmethod
    def 클래스매서드(cls, parameters)
    => cls == 클래스 자기 자신
    
와 같이 정의
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
        
    @classmethod
    def get_info(cls) :
        return "현재 Person의 인스턴스는 {0}개이다".format(cls.count)
        
people = [
    Person("홍길동", 20),
    Person("이순신", 45),
    Person("강감찬", 35)
]

print(Person.get_info())