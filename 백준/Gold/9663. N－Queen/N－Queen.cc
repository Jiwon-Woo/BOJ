#include <bits/stdc++.h>

using namespace std;

int n;
int chess[15][15];
int cnt = 0;
bool flag = false;

bool valid_corrdinate(int x, int y)
{
	return (x > 0 && y > 0 && x <= n && y <= n);
}

void check_queen_valid_move(int x, int y)
{
	chess[x][y] = -x;
	for (int i = 1; i <= n; i++)
	{
		if (chess[x][i] == 0)
			chess[x][i] = x;
		if (chess[i][y] == 0)
			chess[i][y] = x;
		if (valid_corrdinate(x - i, y + i) && chess[x - i][y + i] == 0)
			chess[x - i][y + i] = x;
		if (valid_corrdinate(x + i, y - i) && chess[x + i][y - i] == 0)
			chess[x + i][y - i] = x;
		if (valid_corrdinate(x - i, y - i) && chess[x - i][y - i] == 0)
			chess[x - i][y - i] = x;
		if (valid_corrdinate(x + i, y + i) && chess[x + i][y + i] == 0)
			chess[x + i][y + i] = x;
	}
}

void unchecked_queen_valid_move(int x, int y)
{
	for (int i = 1; i <= n; i++)
	{
		if (chess[x][i] == x)
			chess[x][i] = 0;
		if (chess[i][y] == x)
			chess[i][y] = 0;
		if (valid_corrdinate(x - i, y + i) && chess[x - i][y + i] == x)
			chess[x - i][y + i] = 0;
		if (valid_corrdinate(x + i, y - i) && chess[x + i][y - i] == x)
			chess[x + i][y - i] = 0;
		if (valid_corrdinate(x - i, y - i) && chess[x - i][y - i] == x)
			chess[x - i][y - i] = 0;
		if (valid_corrdinate(x + i, y + i) && chess[x + i][y + i] == x)
			chess[x + i][y + i] = 0;
	}
	chess[x][y] = 0;
}

void solution(int k)
{
	if (k == n + 1)
	{
		cnt++;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (chess[k][i] == 0)
		{
			check_queen_valid_move(k, i);
			solution(k + 1);
			unchecked_queen_valid_move(k, i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	solution(1);
	cout << cnt;

	return 0;
}