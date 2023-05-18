#include <iostream>
#include <deque>

using namespace std;

int m, n;
int tomato[1000][1000];
int unripe = 0;
int day = 0;
deque<pair<int, int>> ripe;
pair<int, int> tool[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomato[i][j];
			if (tomato[i][j] == 0)
			{
				unripe++;
			}
			else if (tomato[i][j] == 1)
			{
				ripe.push_back(make_pair(i, j));
			}
		}
	}

	while (!ripe.empty() && unripe > 0)
	{
		deque<pair<int, int>> temp = ripe;
		while (!temp.empty())
		{
			pair<int, int> curr = temp.front();
			temp.pop_front();
			ripe.pop_front();

			for (pair<int, int> t : tool)
			{
				int x = curr.first + t.first;
				int y = curr.second + t.second;
				if (x >= 0 && y >= 0 && x < n && y < m && tomato[x][y] == 0)
				{
					tomato[x][y] = tomato[curr.first][curr.second] + 1;
					ripe.push_back(make_pair(x, y));
					unripe--;
				}
			}
		}
		day++;
	}

	cout << (unripe == 0 ? day : -1);
}