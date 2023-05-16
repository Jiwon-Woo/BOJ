#include <iostream>
#include <deque>

using namespace std;

int n, m;
int maze[100][100];
int path[100][100];

pair<int, int> tool[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs()
{
	deque<pair<int, int>> q;

	q.push_back(make_pair(0, 0));
	path[0][0] = 1;

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop_front();

		for (pair<int, int> t : tool)
		{
			int x = curr.first + t.first;
			int y = curr.second + t.second;
			if (x >= 0 && y >= 0 && x < n && y < m && maze[x][y] && !path[x][y]) {
				q.push_back(make_pair(x, y));
				path[x][y] = path[curr.first][curr.second] + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++)
		{
			maze[i][j] = temp[j] - '0';
		}
	}

	dfs();
	cout << path[n - 1][m - 1];
	
	return 0;
}