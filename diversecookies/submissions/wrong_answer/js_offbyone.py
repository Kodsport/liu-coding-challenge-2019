#!/usr/bin/env python3
n, a, b, c = map(int, input().split())
mx = max(a, b, c)
rest = sum([a, b, c]) - mx
leftover = max(0, mx - n - rest - 1)
print(a + b + c - leftover)
