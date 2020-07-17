# map 객체가 따로 존재함

data = list("ABCDEFG")

result = list(map(lambda x : x.lower(), data))
print(result)