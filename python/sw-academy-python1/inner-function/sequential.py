data = "Hello"

print(list(data))
# ['H', 'e', 'l', 'l', 'o']
print(tuple(data))
# ('H', 'e', 'l', 'l', 'o')
print(set(data))
# {'e', 'H', 'l', 'o'}
print(dict(enumerate(data)))
# {0: 'H', 1: 'e', 2: 'l', 3: 'l', 4: 'o'} 