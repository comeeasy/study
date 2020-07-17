# 조건에 해당하는 항복을 걸러내는 함수
# filter(조건 함수, data)

def is_even(num) :
    return num % 2 == 0

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
ret_val = filter(is_even, numbers)
# ret_val = filter(lambda x : x % 2 == 0, numbers)

print(list(ret_val))