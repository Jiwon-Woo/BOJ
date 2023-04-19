import sys
from collections import deque

t = int(input())
for _ in range(t):
	p = sys.stdin.readline().strip()
	n = int(input())
	s = sys.stdin.readline().strip()
	if (n != 0):
		arr = deque(list(s[1:-1].split(',')))
	else:
		arr = []
	reverse = -1
	for ac in p:
		if (len(arr) != 0 and ac == 'R'):
			reverse *= -1
		elif (len(arr) != 0 and ac == 'D'):
			if (reverse == -1):
				arr.popleft()
			else:
				arr.pop()
		elif (len(arr) == 0 and ac == 'D'):
			arr = "error"
			break
	if (arr != "error"):
		if (reverse == 1):
			arr.reverse()
		arr = ",".join(arr)
		print(f'[{arr}]')
	else:
		print(arr)