import sys

N, H = map(int, sys.stdin.readline().split())

line = [0 for _ in range(H)]
for i in range(N):
    length = int(sys.stdin.readline())
    if i % 2 == 0:
        line[0] += 1
        line[length] -= 1
    else:
        line[H - length] += 1

answer = [0 for _ in range(H)]
for i in range(H):
    if i == 0:
        answer[0] = line[0]
    else:
        answer[i] = answer[i - 1] + line[i]

mini = min(answer)
print(mini, answer.count(mini))