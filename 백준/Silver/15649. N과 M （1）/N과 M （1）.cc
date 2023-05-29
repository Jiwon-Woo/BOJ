#include <bits/stdc++.h>

using namespace std;

int n, m;

bool isPrint(vector<int> pre, vector<int> curr)
{
	for (int i = 0; i < m; i++)
	{
		if (pre[i] != curr[i])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	vector<int> nums;
	for (int i = 0; i < n; i++)
		nums.push_back(i + 1);

	vector<int> pre(m, 0);

	do
	{
		if (!isPrint(pre, nums))
		{
			for (int i = 0; i < m; i++)
			{
				cout << nums[i] << " ";
				pre[i] = nums[i];
			}
			cout << "\n";
		}
	} while (next_permutation(nums.begin(), nums.end()));

	return 0;
}