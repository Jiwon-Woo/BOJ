import sys

N, M = map(int, sys.stdin.readline().split())


def combination(index, seq, checked):
    global N, M
    if index == M:
        print(*seq)
        return
    for i in range(N):
        if (checked[i]):
            continue
        else:
            checked[i] = True
            seq.append(i + 1)
            combination(index + 1, seq, checked)
            checked[i] = False
            seq.pop()


combination(0, [], [False for _ in range(N)])
