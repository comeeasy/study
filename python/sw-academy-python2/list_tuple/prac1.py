string = 'Python is powerful... and fast; plays well with others; runs everywhere; is friendly & easy to learn; is Open.'

data = [ch for ch in string if ch not in ('a', 'e', 'i', 'o', 'u')]
new_string = ''.join(data)
# new_data = list(new_string)
print(new_string)
# print(new_data)