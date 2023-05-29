#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	vector<int> stairs(300, 0);
	for (int i = 0; i < n; i++)
		cin >> stairs[i];

	vector<vector<int>> dp(300, vector<int>(3, 0));
	dp[0][1] = stairs[0];
	dp[1][1] = stairs[1];
	dp[1][2] = stairs[0] + stairs[1];
	for (int i = 2; i < n; i++)
	{
		// 현재 밟은 계단이 첫번째 연속으로 밟은 계단일 때 -> i - 2
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
		// 현재 밟은 계단이 2번째 연속으로 밟은 계단일 때 -> i - 1 번째 를 반드시 밟는다
		dp[i][2] = dp[i - 1][1] + stairs[i];
	}

	cout << max(dp[n - 1][1], dp[n - 1][2]);
	return 0;
}