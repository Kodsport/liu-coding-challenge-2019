#!/usr/bin/env python3
n, a, b, c = map(int, input().split())
mx = max(a, b, c)
rest = sum([a, b, c]) - mx
leftover = mx - n - rest
print(a + b + c - leftover)
