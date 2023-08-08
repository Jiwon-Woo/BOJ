import sys

N = int(sys.stdin.readline())
arr = []
max_H = 0
for _ in range(N):
    L, H = map(int, sys.stdin.readline().split())
    arr.append([L, H])
    max_H = max(max_H, H)
arr.sort()

answer = 0
left_ptr = 0
curr_h = arr[left_ptr][1]
while curr_h < max_H:
    left_ptr += 1
    answer += curr_h * (arr[left_ptr][0] - arr[left_ptr - 1][0])
    curr_h = max(curr_h, arr[left_ptr][1])

right_ptr = N - 1
curr_h = arr[right_ptr][1]
while curr_h < max_H:
    right_ptr -= 1
    answer += curr_h * (arr[right_ptr + 1][0] - arr[right_ptr][0])
    curr_h = max(curr_h, arr[right_ptr][1])

answer += (arr[right_ptr][0] + 1 - arr[left_ptr][0]) * max_H

print(answer)