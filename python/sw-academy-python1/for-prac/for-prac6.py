# coding : utf-8 -*-

# 다음은 10명의 학생들의 혈액형(A, B, AB, O) 데이터입니다.
# ['A', 'A', 'A', 'O', 'B', 'B', 'O', 'AB', 'AB', 'O']
# for 문을 이용하여 각 혈액형 별 학생수를 구하십시오.

blood_types = ['A', 'A', 'A', 'O', 'B', 'B', 'O', 'AB', 'AB', 'O']
# num_of_blood_types = [['A', 0], ['B', 0], ['O', 0], ['AB', 0]]
num_of_blood_types = {'A': 0, 'O': 0, 'B': 0, 'AB': 0}

# for blood_type in blood_types :
#    if blood_type == 'A' : num_of_blood_types[]
'''
for blood_type in blood_types :
    for lists in num_of_blood_types :
        if blood_type in lists :
            lists[1] += 1    
'''        

for blood_type in blood_types :
    num_of_blood_types[blood_type] += 1
print(num_of_blood_types)
    