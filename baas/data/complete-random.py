import random

N = 400
print(N)
print(*[random.randint(1, 10000) for _ in range(N)])
for i in range(N):
    print(i, *range(1, i+1))
