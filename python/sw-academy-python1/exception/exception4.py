'''
파이썬에서는 예외 객체를 강제로 일으킬 수 있고
raise 문을 사용하여 일으킴

아래 예
'''

def calc_area(w, h) :
    if w.isdigit() and h.isdigit() :
        return int(w) * int(h)
    else :
        raise ValueError("숫자가 아닌 값이 입력되었습니다")
    
width = input("폭을 입력하세요")
height = input("높이를 입력하세요")

try :
    area = calc_area(width, height)
except