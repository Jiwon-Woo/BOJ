import sys

candy = int(sys.stdin.readline())

answer = 0
for i in range(1, candy // 2):
    b = i
    for j in range(2, candy):
        c = b + j
        a = candy - b - c
        if a > 0 and a % 2 == 0:
            answer += 1

print(answer)