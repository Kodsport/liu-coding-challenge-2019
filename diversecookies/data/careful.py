import random

N = random.randint(2, 100000000)
A = random.randint(0, 100000000)
B = random.randint(0, 100000000)
C = N + A + B + random.randint(-10, 10)
print(N, A, B, C)
