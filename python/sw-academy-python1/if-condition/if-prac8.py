# -*- coding : utf-8 -*-

# 100~300 사이의 숫자에서 각각의 자리 숫자가 짝수인 숫자를 찾아 콤마(,)로 구분해 출력하는 프로그램을 작성하십시오.
print_list = []

for i in range(100, 301) :
    # str_num = str(i)
    list_num = list(str(i))
        
    flag = True
    for digit in list_num :
        if int(digit) % 2 != 0 :
            flag = False
            break
    
    if flag :
        print_list.append(str(i))

print(','.join(print_list))
    
