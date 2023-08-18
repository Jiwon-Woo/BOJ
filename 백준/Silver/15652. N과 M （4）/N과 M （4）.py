import sys

N, M = map(int, sys.stdin.readline().split())


def recur(idx, output):
    if idx == M:
        print(*output)
        return

    for i in range(N):
        if len(output) == 0 or output[-1] <= i + 1:
            output.append(i + 1)
            recur(idx + 1, output)
            output.pop()


recur(0, [])
