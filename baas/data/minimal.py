import random

N = 2
print(N)
print(*[random.randint(1, 10000) for _ in range(N)])
for i in range(N):
    if i == 0: print("0")
    else:
        print("1 {}".format(i))
