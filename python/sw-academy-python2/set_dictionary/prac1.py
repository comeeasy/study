'''
아래의 상품 딕셔너리 데이터를 가격에 따라 내림차순으로 정렬하는 프로그램을 작성하십시오.
 
"TV": 2000000,
"냉장고": 1500000,
"책상": 350000,
"노트북": 1200000,
"가스레인지": 200000,
"세탁기": 1000000,
'''

households = {
    "TV": 2000000,
    "냉장고": 1500000,
    "책상": 350000,
    "노트북": 1200000,
    "가스레인지": 200000,
    "세탁기": 1000000
}

# households에 있는 값들을 tuple 형식의 list로 반환 <- households.items()
# sort시 key값을 key=compareFunction(x) 와 같이 나타낼 수 있고
# 이를 람다 식으로 표현함
# 각 리스트를 정렬할 때 
new_hh = sorted(households.items(), key=lambda x : x[1])
new_hh.reverse()

for key, value in dict(new_hh).items() :
    print("{0}: {1}".format(key, value))