#include <iostream>
#include <deque>

using namespace std;

int n, m;
int paper[500][500];
int check[500][500];

pair<int, int> tool[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(pair<int, int> coordi)
{
	int size = 1;
	deque<pair<int, int>> q;
	q.push_back(coordi);
	check[coordi.first][coordi.second] = 1;

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop_front();
		for (pair<int, int> t : tool)
		{
			int x = curr.first + t.first;
			int y = curr.second + t.second;
			if (x >= 0 && x < n && y >= 0 && y < m && paper[x][y] && !check[x][y])
			{
				q.push_back(make_pair(x, y));
				check[x][y] = 1;
				size++;
			}
		}
	}
	return size;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int size = 0;
	int num = 0;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (paper[i][j] && !check[i][j])
			{
				size = max(bfs(make_pair(i, j)), size);
				num++;
			}
		}
	}

	cout << num << '\n' << size;

	return 0;
}