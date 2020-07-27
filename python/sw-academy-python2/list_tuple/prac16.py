'''
항목 값으로는 0을 갖는 2*3*4 형태의 3차원 배열을 생성하는
리스트 내포 기능을 이용한 프로그램을 작성하십시오.
'''

dim3 = [0 for i in range(0, 4)]
dim2 = [dim3 for i in range(0, 3)]
matrix = [dim2 for dim1 in range(0, 2)]

print(matrix)