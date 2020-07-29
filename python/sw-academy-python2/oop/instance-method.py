class Person :
    def __init__(self, name, age) :
        self.name = name      
        self.age  = age
        print(self.name, "이 생성")
    
    def __del__(self) :
        print(self.name, "이 제거")
        
    def to_str(self) :
        return "{0}\t{1}".format(self.name, self.age)
    
members = [
    Person("홍길동", 20),
    Person("이순신", 45),
    Person("강감찬", 35)
]

for member in members :
    print(member.to_str())
    
