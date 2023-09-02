import sys

N = int(sys.stdin.readline())
interviews = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [0 for _ in range(N + 1)]


for index in range(N)[::-1]:
    ti, pi = interviews[index]
    if index + ti > N:
        dp[index] = dp[index + 1]
    else:
        dp[index] = max(dp[index + ti] + pi, dp[index + 1])

print(dp[0])
