'''
다음 결과와 같이 문자열을 입력하면 짝수 인덱스를 
가진 문자들을 출력하는 프로그램을 작성하십시오.
'''

string = input()
print("".join([string[i] for i in range(0, len(string)) if i % 2 == 0]))

