import sys

n, k = map(int, sys.stdin.readline().split())

def combinations(n, k):
	if n == 0 or n == 1:
		return 1
	dp = [0 for _ in range(n + 1)]
	dp[0], dp[1] = [1], [1, 1]
	for i in range(2, n + 1):
		sub_dp = [0 for _ in range(i + 1)]
		sub_dp[0], sub_dp[i] = 1, 1
		for j in range(1, i // 2 + 1):
			sub_dp[j] = dp[i - 1][j - 1] + dp[i - 1][j]
			sub_dp[i - j] = sub_dp[j]
		dp[i] = sub_dp
		del sub_dp
	ret = dp[n][k] % 10007
	return ret

print(combinations(n, k))