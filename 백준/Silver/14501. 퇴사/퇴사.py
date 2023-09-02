import sys

N = int(sys.stdin.readline())
interviews = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dp = [-1 for _ in range(N + 1)]


def recur(index):
    global interviews

    if index > N:
        return -15001
    if index == N:
        return 0
    if dp[index] > -1:
        return dp[index]

    ti, pi = interviews[index]
    dp[index] = max(recur(index + ti) + pi, recur(index + 1))
    return dp[index]


recur(0)
print(dp[0])
