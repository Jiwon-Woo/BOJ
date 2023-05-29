#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	vector<int> methods(n + 1, 0);
	methods[1] = 1;
	methods[2] = 2;

	for (int i = 3; i < n + 1; i++)
		methods[i] = (methods[i - 1] + methods[i - 2]) % 10007;

	cout << methods[n];

	return 0;
}