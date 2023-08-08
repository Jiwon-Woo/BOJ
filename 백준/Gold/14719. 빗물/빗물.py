import sys

H, W = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))
maxHeight = max(arr)

answer = 0

left = 0
currHeight = -1
for i in range(W):
    if arr[i] == maxHeight:
        left = i
        break
    currHeight = max(currHeight, arr[i])
    answer += currHeight - arr[i]

right = 0
currHeight = -1
for i in range(W - 1, -1, -1):
    if arr[i] == maxHeight:
        right = i
        break
    currHeight = max(currHeight, arr[i])
    answer += currHeight - arr[i]


for i in range(left, right + 1):
    answer += maxHeight - arr[i]

print(answer)
