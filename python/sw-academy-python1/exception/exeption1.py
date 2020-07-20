# if문을 이용한 예외 처리
# 사전에 예상 가능한 예외를 처리하는 것

width = input("폭 입력")
height = input("높이 입력")
area = 0

if width.isdigit() and height.isdigit() :
    area = int(width) * int(height)
    print(area)
    
else :
    print("숫자 입력")
    
print("프로그램 종료")

'''
1. try ~ except 문
    예외가 발생했을 때 처리
2. try ~ except ~ else 문
    예외가 발생했을 때, 발생하지 않았을 때 처리
3. try ~ except ~ else ~ finally 문
    예외가 발생했을 떄, 발생하지 않았을 때, 예외 발생 상관없이 처리
'''

width = input("폭 입력(예외 처리)")
height = input("높이 입력 (예외 처리)")
area = 0

try :
    area = int(width) * int(height)
    # ValueError 발생 구문
except :
    print("숫자가 아닌 값이 입력 되었습니다.")
else :
    print("{0} * {1} = {2}".format(int(width), int(height), area))
    
print('프로그램 종료')

# 홀리;

