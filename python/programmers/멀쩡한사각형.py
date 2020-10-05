
def gcd(a, b) : return a if b == 0 else gcd(b, a%b)

w = 8
h = 12
answer = w*h - (w+h) + gcd(w, h)
print(answer)








