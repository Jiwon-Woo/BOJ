import sys
from operator import itemgetter
import math

N, S = map(int, sys.stdin.readline().split())

moles = [(0, 0, 0)] + sorted([tuple(map(int, sys.stdin.readline().split())) for _ in range(N)], key=itemgetter(-1))
dp = [0] + [-1 for _ in range(N + 1)]

for idx in range(1, N + 1):
    X, Y, T = moles[idx]
    for curr in range(idx):
        x, y, t = moles[curr]
        if dp[curr] != -1 and math.sqrt((X - x)**2 + (Y - y)**2) <= (T - t) * S:
            dp[idx] = max(dp[curr] + 1, dp[idx])

print(max(dp))

