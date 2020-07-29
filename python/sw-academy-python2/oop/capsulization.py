class Person :
    def __init__(self, name, age) :
        self.__name = name      
        self.__age  = age
        print(self.name, "이 생성")
    
    def __del__(self) :
        print(self.name, "이 제거")
        
    def to_str(self) :
        return "{0}\t{1}".format(self.name, self.age)
    
    def get_name(self) :
        return self.__name
    # => __name 필드에 대해서는 getter 메서드만 제공
    
    def get_age(self) :
        return self.__age
    
    def set_age(self, age) :
        if age < 0 :
            raise TypeError("나이는 0이상의 값만 허용합니다.")
        self.__age = age
    
members = [
    Person("홍길동", 20),
    Person("이순신", 45),
    Person("강감찬", 35)
]

for member in members :
    print(member.to_str())