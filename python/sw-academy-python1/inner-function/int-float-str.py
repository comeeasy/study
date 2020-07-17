x = '10'
y = '3c'
z = 4.5

# int(data, base(진수))
print(int(x, 2))
print(int(x))
print(int(x, 8))
print(int(x, 16))

# error
#print(int(y, 2))
# 16진수로 읽어서 10진수로 return
print(int(y, 16))

print(int(z))