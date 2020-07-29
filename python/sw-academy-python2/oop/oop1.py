members = [
    dict(name="홍길동", age=20),
    {"name" : "이순신", "age" : 45},
    {"name" : "강감찬", "age" : 35},
]

for member in members :
    print("{0}\t{1}".format(member["name"], member["age"]))
