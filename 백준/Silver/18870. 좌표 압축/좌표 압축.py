import sys

n = int(input())
x = list(map(int, sys.stdin.readline().split()))
x_index = [0 for _ in range(n)]
answer = [0 for _ in range(n)]

for i in range(n):
	x_index[i] = x[i], i
x_index.sort()

j = 0
answer[x_index[0][1]] = j
for i in range(1, n):
	if (x_index[i - 1][0] != x_index[i][0]):
		j += 1
	answer[x_index[i][1]] = j

for factor in answer:
	print(factor, end=' ')