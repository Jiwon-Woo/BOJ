import sys

nk = list(map(int, sys.stdin.readline().split()))
wv = [list(map(int, sys.stdin.readline().split())) for _ in range(nk[0])]
bag = [[0 for _ in range(nk[1] + 1)] for _ in range(nk[0] + 1)]

for i in range(nk[0]):
	for j in range(1, nk[1] + 1):
		if j < wv[i][0]:
			bag[i + 1][j] = bag[i][j]
		else:
			bag[i + 1][j] = max(bag[i][j], bag[i][j - wv[i][0]] + wv[i][1])

print(bag[nk[0]][nk[1]])