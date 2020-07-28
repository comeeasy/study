'''
문자열을 마스크 문자열로 치환하기
'''

string = "파이썬은 클래스를 이용해 객체를 생성하는 객체지향 프로그래밍 언어입니다."
print(string)

input_str = input("마스킹할 문자열을 입력해주세요 : ")
find_str  = input("찾을 문자열을 입력해주세요 : ")

find_idx = 0
while True :
    find_idx = string.find(find_str)
    if find_idx == -1 :
        break
    print("find_idx = ", find_idx)
    print("[{0}] ~ [{1}]".format(find_idx, find_idx + len(find_str) - 1))
    string = string[0:find_idx] + input_str + string[find_idx + len(find_str):len(string)]
    print(string)
