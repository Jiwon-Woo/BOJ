import sys

n = int(sys.stdin.readline())

flag = 1
while flag * flag <= n:
    flag += 1

print(flag - 1)