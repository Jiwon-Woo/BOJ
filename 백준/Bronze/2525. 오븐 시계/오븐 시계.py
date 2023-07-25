import sys

hour, min = map(int, sys.stdin.readline().split())
time = int(sys.stdin.readline().strip())

hour = hour + (min + time) // 60
min = (min + time) % 60

print(hour % 24, min, end=' ')