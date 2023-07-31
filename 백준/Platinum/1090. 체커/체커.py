import sys

n = int(sys.stdin.readline())
checkers = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

answer = [-1 for _ in range(n)]

x_list = set()
y_list = set()
for checker in checkers:
    x_list.add(checker[0])
    y_list.add(checker[1])

for x in x_list:
    for y in y_list:
        distance = []
        for checker in checkers:
            distance.append(abs(x - checker[0]) + abs(y - checker[1]))
        distance.sort()
        for i in range(n):
            d = sum(distance[0:i+1])
            if answer[i] == -1 or d < answer[i]:
                answer[i] = d

print(*answer)