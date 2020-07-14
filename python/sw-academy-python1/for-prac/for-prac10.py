# -*- coding : utf-8 -*-

'''
    lst = [1,2,3,4,5]
    print(",".join([str(i) for i in lst] )) #또는
    print(",".join(map(str, lst)))
'''

number = input()
num_dict = {'0':0, '1':0, '2':0, '3':0, '4':0, '5':0, '6':0, '7':0, '8':0, '9':0}

print("0 1 2 3 4 5 6 7 8 9")
for i in number :
    num_dict[i] += 1

num_list = list(num_dict.values())
num_list = list(map(str, num_list))           

# num_str = " ".join(str(i) for i in num_list)
# num_str = " ".join(map(str, num_list))
print(" ".join(num_list))

'''
    아직 str(i) for i in list 나 map() 함수를 알지 못하기 때문에
    일단은 사용하겠지만 map함수는 iterator 객체를 반환하여 효율적인
    메모리 사용이 가능하게 한다. list 자체를 반환하지 않는다.
'''    