# element중에 하나라도 True가 있으면 True return

val1 = [True, True]
val2 = ['', '']
val3 = [10, 20, 0]
val4 = [[]]

print(any(val1))
print(any(val2))
print(any(val3))
print(any(val4))
