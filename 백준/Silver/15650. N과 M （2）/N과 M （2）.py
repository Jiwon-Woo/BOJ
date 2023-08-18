import sys

N, M = map(int, sys.stdin.readline().split())

answer = []


def combination(idx, output):
    global answer

    if idx == M:
        sorted_output = sorted(output)
        if sorted_output not in answer:
            answer.append(sorted_output)
        return

    for i in range(N):
        if i + 1 not in output:
            output.append(i + 1)
            combination(idx + 1, output)
            output.pop()


combination(0, [])
for e in answer:
    print(*e)
