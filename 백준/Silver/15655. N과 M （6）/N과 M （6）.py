import sys

N, M = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
nums.sort()

answer = []


def recur(idx, output):
    global answer

    if idx == M:
        sorted_output = sorted(output)
        if sorted_output not in answer:
            answer.append(sorted_output)
        return

    for num in nums:
        if num not in output:
            output.append(num)
            recur(idx + 1, output)
            output.pop()


recur(0, [])
for e in answer:
    print(*e)
