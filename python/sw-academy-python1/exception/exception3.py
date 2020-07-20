'''
    다중 exception문을 이용한 예외 객체에 따른 처리의 분기
'''

print("나누기 연산의 결과를 구해봅시다")
x, y, result = 0, 0, 0

try :
    x = int(input("나누어질 수 입력"))
    y = int(input("나눌 수 입력"))
    result = x / y
except ValueError as ve :
    print("입력은 반드시 숫자를 사용해야 합니다")
    print("{0} : {1}".format(type(ve), ve))
except ZeroDivisionError as ze :
    print("0으로 나눌 수 없습니다")
    print("{0} : {1}".format(type(ze), ze))
except Exception as ex :
    print("예상치 못한 예외가 발생했습니다")
    print("{0}: {1}".format(type(ex), ex))
else :
    print("{0} / {1} = {2}".format(x, y, result))
finally :
    print("finally block")

print("프로그램 종료")