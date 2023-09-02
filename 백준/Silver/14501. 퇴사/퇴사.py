import sys

N = int(sys.stdin.readline())
interviews = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
max_profit = 0


def recur(index, profit):
    global interviews, max_profit

    if index == N:
        max_profit = max(profit, max_profit)
        return

    ti, pi = interviews[index]
    if index + ti <= N:
        recur(index + ti, profit + pi)
    recur(index + 1, profit)


recur(0, 0)
print(max_profit)
