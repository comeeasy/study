# chr()
# 정수 형태의 값을 인자로 받아 해당 코드의
# 문자로 반환하는 함수

# ord()
# 문자를 인자로 전달 받아 유니코드 값(10진 정수)
# 로 return

# hex()
# 10진수 값을 받아 16진수 값으로 return

# A
val = 65
print(chr(val))

# 가
val_hex = 0xac00
print(chr(val_hex))

# 65
val = 'A'
print(ord(val))

# 0xac00
val = '가'
print(hex(ord(val)))