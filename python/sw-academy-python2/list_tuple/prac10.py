'''
콤마(,)로 구분된 정수 값을 입력받아 리스트와 튜플 객체를 생성하는 코드를 작성하십시오.
'''

x = input()
num_list = list(map(int, x.split(', ')))
num_tuple = tuple(num_list)

print(num_list)
print(num_tuple)
