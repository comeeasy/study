data_set = {10, 20, "파이썬", "파이썬"}
print(data_set)

data_set = set(range(10, 21, 2))
print(data_set)

data_set = set("Better Tommorrow")
print(data_set)

# 기본 연산
# 1. intersection, union, difference

data1 = {1, 2, 2, 3, 4, 4, 5, 6, 7, 7, 7, 11}
data2 = {2, 3, 5, 9, 11, 12, 15}

print(data1 & data2)
print(data1 | data2)
print(data1 - data2)

# 항목 추가
data = {1, 2, 3}
# 1, 2, 3

data.add(3)
data.add(4)

# 새로운 set 추가 union?
data.update({4, 5, 6})

data = set(range(1, 11))
print(data)
data.remove(9)
data.remove(2)
print(data)

data.pop()
print(data)

# set compregension
# list, tuple과 같음

# dictionary
# 1. 인덱스를 제공하지 않음 2. 순서의 개념이 없음 3. 중복을 허용하지 않음

data = {
    "홍길동" : 20,
    "이순신" : 45,
    "강감찬" : 35
}

print(data)

# 키=값 형식으로 작성하고 키를 문자열로 작성하지 않도록 주의 
data2 = dict(홍길동=20, 이순신=45, 강감찬=35)

# 항목 접근
print(data2["홍길동"])      # 20

# 딕셔너리 항목 추가
data["을지문덕"] = 40   # 객체이름[중복되자 않은 키] = 값
# 와 같이 항목추가 가능
print(data)
# updat함수
data.update({"신사임당" : 50, "유관순" : 16})
print(data)

# dictoinary는 키값을 가지고 항목에 존재 유무를 확인함
# dictionary comprehension
data2 = {key: data[key] for key in data.keys()}
print(data, data2)