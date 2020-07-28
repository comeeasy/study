'''
다음과 같이 사용자가 입력한 문장에서 
숫자와 문자를 구별해 각각의 개수를 출력하는 프로그램을 작성하십시오
'''

string = input()

LETTER = 0
DIGITS = 0
for ch in string :
    if ch.isalpha() :
        LETTER += 1
    elif ch.isdecimal() :
        DIGITS += 1
        
print("LETTERS {0}\nDIGITS {1}".format(LETTER, DIGITS))

