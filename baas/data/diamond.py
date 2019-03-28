import random

N = 397
print(N)
print(*[random.randint(1, 10000) for _ in range(N)])
for i in range(N):
    if i%4 == 0:
        if i != 0:
            print("3", *range(i - 2, i + 1))
        else:
            print(0)
    else:
        print("1", 1 + i - i % 4)
