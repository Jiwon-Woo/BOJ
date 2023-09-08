#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N, S;

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;

	vector<vector<int> > moles(N + 1, vector<int>(3, 0));

	for (int i = 1; i <= N; i++)
		cin >> moles[i][1] >> moles[i][2] >> moles[i][0];
	sort(moles.begin(), moles.end());

	vector<int> dp(N + 1, 0);
	int max_value = 0;

	for (int idx = 1; idx <= N; idx++)
	{
		int T = moles[idx][0];
		int X = moles[idx][1];
		int Y = moles[idx][2];

		for (int curr = 0; curr < idx; curr++)
		{
			if (curr > 0 && dp[curr] == 0)
				continue;

			int t = moles[curr][0];
			int x = moles[curr][1];
			int y = moles[curr][2];

			if (pow(X - x, 2) + pow(Y - y, 2) <= (long long)(T - t) * (T - t) * (long long)S * S)
			{
				dp[idx] = max(dp[idx], dp[curr] + 1);
				max_value = max(max_value, dp[idx]);
			}
		}
	}

	cout << max_value << endl;

	return 0;
}
