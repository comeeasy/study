'''
    "ADCBBBBCABBCBDACBDCAACDDDCAABABDBCBCBDBDBDDABBAAAAAAADADBDBCBDABADCADC"와
    같은 문자열이 주어지고, A는 4점, B는 3점, C는 2점, D는 1점이라고 할 때 문자열에 사용된
    알파벳 점수의 총합을 map 함수와 람다식을 이용해 구하십시오.
'''

data = "ADCBBBBCABBCBDACBDCAACDDDCAABABDBCBCBDBDBDDABBAAAAAAADADBDBCBDABADCADC"
scores = list(map(lambda x : abs(ord(x) - 69) ,data))
print(sum(scores))
