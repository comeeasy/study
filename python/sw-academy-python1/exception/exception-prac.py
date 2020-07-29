'''
    사용자로부터 인덱스를 입력 받아 숫자로 변환하는 함수
    
    data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    를 선언하고 이를 index를 이용하여 참조할건데 
    각 예외 상황에 대하여 
    ValueError, indexError
'''

def index_to_number() :
    data = list(range(1, 11))
    
    index = input("인덱스로 사용할 숫자를 입력하세요 : ")
    
    try :
        data[int(index)]
    except ValueError as ve :
        print("{0}: {1}".format(type(ve), ve))
        print("0 - 9 까지의 숫자를 입력하세요")
        # raise ValueError
    except IndexError as ie :
        print("{0}: {1}".format(type(ie), ie))
        print("0 - 9 까지의 숫자를 입력하세요")
        # raise IndexError
    except Exception as ex :
        print("{0}: {1}".format(type(ex), ex))
        print("알 수 없는 오류")
        # raise Exception
    else :
        return data[int(index)]

print("{0} is returned".format(index_to_number()))
print("프로그램 종료")