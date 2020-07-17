# List, Tuple, string과 같은 시퀀스형을 입력받아
# 인덱스를 포함하는 튜플객체를 항목으로 구성하는 enumerate 객체를 return하는 함수

data = [10, 20, 30, 40, 50]

print(enumerate(data))

for obj in enumerate(data) :
    print("{0}: {1}, {2}".format(type(obj), obj[0], obj[1]))