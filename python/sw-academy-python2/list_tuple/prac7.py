'''
리스트 내포 기능을 이용하여 1부터 20사이의 숫자 중 3의 배수가 아니거나
5의 배수가 아닌 숫자들의 제곱 값으로 구성된 리스트 객체를 출력하는 
프로그램을 작성하십시오.
'''

print([x*x for x in range(1, 21) if x % 3 != 0 and x % 5 != 0])