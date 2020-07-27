'''
다음의 결과와 같이 정수를 입력하면 약수를 리스트에 
추가해 출력하는 코드를 작성하십시오.
'''
x = int(input())

data = [num for num in range(1, x+1) if x % num == 0]
print(data)