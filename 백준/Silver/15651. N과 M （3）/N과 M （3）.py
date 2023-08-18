import sys

N, M = map(int, sys.stdin.readline().split())


def recur(idx, output):
    if idx == M:
        print(output)
        return

    for i in range(N):
        recur(idx + 1, output + str(i + 1) + ' ')


recur(0, '')
