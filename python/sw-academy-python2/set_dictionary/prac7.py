'''
다음의 결과와 같이 입력된 문자열의 문자 빈도수를 구하는 프로그램을 작성하십시오.
'''

string = list(input())

ch_frequency = {ch: string.count(ch) for ch in string}
for ch, frequency in ch_frequency.items() :
    print("{0},{1}".format(ch, frequency))