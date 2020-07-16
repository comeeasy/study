##########################################
'''
    인자로 전달된 두 개의 문자열 중 길이가 더 긴 문자열을 출력하는 함수를 정의하고
    결과를 출력하는 프로그램을 작성하십시오.
'''
##########################################

def which_longer(str_list) :
    length = 0
    index  = 0
    
    for i in range(0, len(str_list)) :
        if len(str_list[i]) > length :
            length = len(str_list[i])
            index  = i
    
    return str_list[i]
        
##########################################

str_list = list(input().split(', '))
print(which_longer(str_list))

##########################################