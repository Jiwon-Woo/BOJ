#include <bits/stdc++.h>

using namespace std;

int x;
int nums[1000001];
int path[1000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> x;

	nums[1] = 0;
	nums[2] = 1; // 2에서 1로 가기 까지 필요한 최소 연산 횟수 (2 - 1 or 2 / 2)
	path[2] = 1;

	for (int i = 3; i <= x; i++)
	{
		if (i % 6 == 0 && (nums[i / 3] < nums[i - 1] || nums[i / 2] < nums[i - 1]))
		{
			if (nums[i / 3] < nums[i / 2])
			{
				nums[i] = nums[i / 3] + 1;
				path[i] = i / 3;
			}
			else
			{
				nums[i] = nums[i / 2] + 1;
				path[i] = i / 2;
			}
		}
		else if (i % 3 == 0 && nums[i / 3] < nums[i - 1])
		{
			nums[i] = nums[i / 3] + 1;
			path[i] = i / 3;
		}
		else if (i % 2 == 0 && nums[i / 2] < nums[i - 1])
		{
			nums[i] = nums[i / 2] + 1;
			path[i] = i / 2;
		}
		else
		{
			nums[i] = nums[i - 1] + 1;
			path[i] = i - 1;
		}
	}
	cout << nums[x] << "\n";

	int idx = x;
	while (idx > 0)
	{
		cout << idx << " ";
		idx = path[idx];
	}

	return 0;
}