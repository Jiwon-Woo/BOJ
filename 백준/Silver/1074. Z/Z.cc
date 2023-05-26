#include <bits/stdc++.h>

using namespace std;

// 크기가 2^n * 2^n 짜리 사각형에서 r,c를 몇번째로 방문할지
int solution(int n, int r, int c)
{
	if (n == 0)
		return 0;

	if (r < pow(2, n - 1) && c < pow(2, n - 1)) // 만약 첫번째 사각형이면
	{
		return solution(n - 1, r, c);
	}
	else if (r < pow(2, n - 1) && c >= pow(2, n - 1)) // 만약 두번째 사각형이면
	{
		return pow(2, n - 1) * pow(2, n - 1) + solution(n - 1, r, c - pow(2, n - 1));
	}
	else if (r >= pow(2, n - 1) && c < pow(2, n - 1)) // 만약 세번째 사각형이면
	{
		return pow(2, n - 1) * pow(2, n - 1) * 2 + solution(n - 1, r - pow(2, n - 1), c);
	}
	else // 만약 네번째 사각형이면
	{
		return pow(2, n - 1) * pow(2, n - 1) * 3 + solution(n - 1, r - pow(2, n - 1), c - pow(2, n - 1));
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;

	cout << solution(n, r, c) << '\n';

	return 0;
}