#!/usr/bin/env python3
n, a, b, c = map(int, input().split())
ans = 0
cur = [[a, 0], [b, 1], [c, 2]]
for i in range(n):
    last = -1
    while True:
        cur = list(sorted(cur, reverse=True))
        for i, v in enumerate(cur):
            if v[0] == 0 or last == v[1]: continue
            v[0] -= 1
            last = v[1]
            ans += 1
            break
        else:
            break
print(ans)
