import sys

N, M = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
nums.sort()


def recur(idx, output):
    if idx == M:
        print(output)
        return

    for num in nums:
        recur(idx + 1, output + str(num) + " ")


recur(0, "")
