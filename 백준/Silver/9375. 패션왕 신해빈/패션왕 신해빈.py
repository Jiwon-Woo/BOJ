import sys
from operator import itemgetter

t = int(input())
cases = []
for i in range(t):
	clothes = []
	n = int(input())
	clothes = [list(sys.stdin.readline().split()) for _ in range(n)]
	cases.append(clothes)

def solution(clothes):
	if len(clothes) == 0:
		return 0
	clothes.sort(key=itemgetter(1))
	sort_case = []
	item, kind = 1, 1
	for i in range(1, len(clothes)):
		if clothes[i][1] == clothes[i - 1][1]:
			item += 1
		else:
			sort_case.append(item)
			kind += 1
			item = 1
	sort_case.append(item)
	ret = 1
	for num in sort_case:
		ret *= num + 1
	ret -= 1 
	return ret

for clothes in cases:
	print(solution(clothes))