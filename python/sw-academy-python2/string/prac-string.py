# 문자열 연결

message = "안녕하세요"
guest   = '홍길동'

greeting = guest + "님, " + message
print (greeting)

# 문자열 반복
print("=" * 40)
print("-" * 13, end='') # 매개변수를 통해 줄바꿈 기능을 없앰
print(" 문자열 반복 ", end='')
print("-" * 13)
print("=" * 40)

# 문자의 선택
string = "안녕하세요, 파이썬 입니다"

idx = 0
cnt = len(string)
while True :
    print("string[{0}] : {1}".format(idx, string[idx]))
    if idx == cnt - 1 :
        break
    idx += 1
        
print("-" * 20)

# 문자열의 범위 선택
string2 = "와우! 안녕하세요, 파이썬 입니다"

start = input("시작 인덱스를 입력하세요 : ")
end   = input("종료 인덱스를 입력하세요 : ")

try :
    start = int(start)
except ValueError :
    start = None       # 좋다
    
try :
    end = int(end)
except ValueError :
    end = None          # 좋음 ㅋ
    
print("{0}".format(string2[start:end]))

# 문자열 함수
string3 = "Have a nice day!"

print(string3)
input_str = input("위에서 찾고자 하는 문자열을 입력하세요")

print("'{0}'에서 '{1}'은 {2}번 나타납니다.".format(string3, input_str, string3.count(input_str)))

# 문자열 찾기
string4 = "파이썬은 클래스를 이용해 객체를 생성하는 객체지향 프로그래밍 언어입니다."

print(string4)
input_str = input("위에서 찾고자 하는 문자열을 입력하세요 : ")

# 문자열을 찾을 경우 시작 인덱스 return, 그렇지 않을 경우 -1 return
idx = string4.find(input_str)

if idx != -1 :
    print("\t'{0}' : [{1}] <= 문자열을 가장 먼저 찾은 위치".format(input_str, idx))
else :
    print("찾을 수 없다")
    
# 첫번째 문자만 대문자로 하는 문자열 반환
string5 = "better tomorrow"

print(string5)
string5 = string5.capitalize()
print(string5)

# 공백 제거
# lstrip : 왼쪽 공백 제거
# rstrip : 오른쪽 공백 제거
# strip  : 양쪽 공백 제거

string6 = "   홍 길동   "
print(string6)
print("lstrip" + string6.lstrip())

string6 = "___ 홍길동 _ __ __  "
print(string6)
# _, ' ', 동 제거 (못 지우는게 나올떄까지)
print("rstrip('_ ')" + string6.rstrip('_ 동'))

# 문자열 교체
string7 = "10....20....30....40....50"
print(string7)
string7 = string7.replace("." * 4, '\t')
print(string7)

# 문자열 자르기
string8 = "10, 20, 30, 40, 50"

string8 = string8.replace(" ", "")
print(string8)

# ','를 기준으로 리스트 생성
string8_list = string8.split(",")
print(string8_list)
