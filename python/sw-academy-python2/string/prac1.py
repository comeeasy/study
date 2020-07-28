'''
다음과 같이 문장을 구성하는 단어를 역순으로 출력하는 프로그램을 작성하십시오.

A better tomorrow
tomorrow better A
'''

string = input()
str_list = string.split(" ")
str_list.reverse()

for word in str_list :
    print(word, end=' ')
print()