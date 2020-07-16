##################################################
'''
    정렬된 숫자를 가진 리스트에서 특정 숫자를 찾는 함수를 정의하고,
    이 함수를 이용해 임의의 숫자의 포함 여부를 출력하는 프로그램을 작성하십시오.
'''
##################################################

def is_num_exist(numlist, num) :
    for val in numlist :
        if num == val :
            return True
    return False

##################################################

num_list = [2, 4, 6, 8, 10]

num1, num2 = 5, 10
print(num_list)
print("{0} => {1}".format(num1, is_num_exist(num_list, num1)))
print("{0} => {1}".format(num2, is_num_exist(num_list, num2)))

##################################################