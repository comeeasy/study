import matplotlib as plt

x = [1, 1/3]
y = [1, 1/2]

for i in range(2, 50) :
    y.append(5/6*y[i-1] - 1/6*y[-2])

plt.plot(x, y)
plt.show()