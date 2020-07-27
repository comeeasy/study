'''
리스트 내포 기능을 활용해 입력된 정수 값 5개의 평균을 출력하는 프로그램을 작성하십시오.
'''

data = []
sum = 0
for i in range(0, 5) :
    data.append(int(input()))
    sum += data[i]
    
print("입력된 값 {0}의 평균은 {1:.1f}입니다.".format(data, sum / 5))