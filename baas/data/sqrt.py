import random

K = 20
L = 19
N = K * L + 1
print(N)
print(*[1 if i % K == 0 else random.randint(2, 10000) for i in range(N)])
for i in range(N):
    if i%K == 0:
        if i != 0:
            print(K - 1, *range(i - K + 2, i + 1))
        else:
            print(0)
    else:
        print("1", 1 + i - i % K)
