#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> process;

// from에서 to로 n개의 원판을 옮긴다.
int hanoi(int from, int to, int n)
{
	// 원판을 하나만 옮길 때에는 1번만 옮기면 된다.
	if (n == 1)
	{
		// 실제로 하나씩 옮길 때 수행과정 저장하기
		process.push_back(make_pair(from, to));
		// cout << from << " " << to << "\n";
		return 1;
	}

	// from에서 to로 n개의 원판을 옮기려면 나머지 공간에 n-1개의 원판을 옮겨두어야 한다.
	// 3개 장대의 인덱스를 전부 더하면 6이므로 나머지 장대는 6에서 from과 to를 빼서 찾는다.
	int other = 6 - from - to;
	int before = hanoi(from, other, n - 1);

	// 그 다음 가장 바닥에 있는 원판을 옮겨둔다.
	int bottom = hanoi(from, to, 1);

	// 다시 other에서 to로 n-1개의 원판을 to로 옮긴다.
	int after = hanoi(other, to, n - 1);
	return before + bottom + after;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;

	// 1번 장대에서 3번 장대로 n개의 원판을 옮긴다.
	cout << hanoi(1, 3, n) << '\n';

	for (pair<int, int> p : process)
	{
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}