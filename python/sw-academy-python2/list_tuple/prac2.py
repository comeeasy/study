'''
다음의 결과와 같이 구구단 2단부터 9단의 결과값 중에 3의 배수거나 7의 배수인 수를
제외한 값을 리스트 객체 result 안에 각 단마다 리스트를 만들어 삽입하고 이를 출력하십시오.
'''

result = []
for i in range(2, 10) :
    if i % 3 != 0 and i % 7 != 0 :
        result.append([j * i for j in range(1, 9) if j % 3 != 0 and j % 7 != 0])
    else :
        result.append([])
        
print(result)