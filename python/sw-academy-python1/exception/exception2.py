''' 
    예외 객체를 참조해 예외 객체의 타입과 오류 메세지 확인
'''

width = input("폭 입력(예외 처리)")
height = input("높이 입력 (예외 처리)")
area = 0

try :
    area = int(width) * int(height)
    # ValueError 발생 구문
    
# 예외가 발생하면 Exception 객체가 주어짐 == 예외가 발생한 객체
except Exception as ex :
    print("{0}: {1}".format(type(ex), ex))
else :
    print("{0} * {1} = {2}".format(int(width), int(height), area))
finally :
    print("finally block")
    
print('프로그램 종료')