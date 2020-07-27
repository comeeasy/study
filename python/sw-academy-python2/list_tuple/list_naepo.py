data = [1, 2, 3, 4, 5]

data1 = []
for item in data :
    data1.append(item)

print(data1)

# 리스트 내포
# 반복 가능한 자료형의 경우 리터럴 안에서 for문을 사용하면
# 내포 기능 사용 가능

data2 = [item for item in data]
print(data2)

data3 = []
for item in data :
    if item % 2 == 1 :
        data3.append(item)

data4 = [item for item in data if item % 2 == 1]

print(data3)
print(data4)