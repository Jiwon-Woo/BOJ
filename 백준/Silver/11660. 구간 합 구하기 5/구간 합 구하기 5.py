import sys

N, M = map(int, sys.stdin.readline().split())

graph = [[0 for _ in range(N + 1)]]
for _ in range(N):
    graph.append([0] + list(map(int, sys.stdin.readline().split())))

problems = []
for _ in range(M):
    problems.append(list(map(int, sys.stdin.readline().split())))


sumGraph = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(N):
    for j in range(N):
        sumGraph[i + 1][j + 1] = sumGraph[i + 1][j] + sumGraph[i][j + 1] - sumGraph[i][j] + graph[i + 1][j + 1]

for i in range(M):
    x1, y1, x2, y2 = problems[i]
    print(sumGraph[x2][y2] - sumGraph[x2][y1 - 1] - sumGraph[x1 - 1][y2] + sumGraph[x1 - 1][y1 - 1])
