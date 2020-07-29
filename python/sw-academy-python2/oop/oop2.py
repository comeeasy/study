def create(name, age) :
    return dict(name=name, age=age)

def to_str(person) :
    return "{0}\t{1}".format(person["name"], person["age"])

members = [
    create("홍길동", 20),
    create("이순신", 45),
    create("강감찬", 35),
]

for member in members :
    print(to_str(member))
    
    