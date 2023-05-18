#include <iostream>
#include <deque>

using namespace std;

int r, c;
char maze[1000][1000];
int maze_fire[1000][1000];
int maze_jihoon[1000][1000];
pair<int, int> jihoon;
deque<pair<int, int>> fire;
pair<int, int> tool[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'J')
				jihoon = make_pair(i, j);
			if (maze[i][j] == 'F')
				fire.push_back(make_pair(i, j));
		}
	}

	while (!fire.empty())
	{
		deque<pair<int, int>> temp = fire;
		while (!temp.empty())
		{
			pair<int, int> curr = temp.front();
			temp.pop_front();
			fire.pop_front();
			for (pair<int, int> t: tool)
			{
				int x = curr.first + t.first;
				int y = curr.second + t.second;
				if (x >= 0 && y >= 0 && x < r && y < c && (maze[x][y] == '.' || maze[x][y] == 'J') && maze_fire[x][y] == 0)
				{
					maze_fire[x][y] = maze_fire[curr.first][curr.second] + 1;
					fire.push_back(make_pair(x, y));
				}
			}
		}
	}

	deque<pair<int, int>> path;
	path.push_back(jihoon);
	int step = 0;
	while (!path.empty())
	{
		pair<int, int> curr = path.front();
		path.pop_front();
		for (pair<int, int> t: tool)
		{
			int x = curr.first + t.first;
			int y = curr.second + t.second;
			if (x < 0 || y < 0 || x >= r || y >= c)
			{
				step = maze_jihoon[curr.first][curr.second] + 1;
				break;
			}
			if (maze[x][y] == '.' && maze_jihoon[x][y] == 0 && (maze_fire[x][y] == 0 || maze_fire[x][y] > maze_jihoon[curr.first][curr.second] + 1))
			{
				maze_jihoon[x][y] = maze_jihoon[curr.first][curr.second] + 1;
				path.push_back(make_pair(x, y));
			}
		}
		if (step)
			break;
	}

	if (step)
		cout << step;
	else
		cout << "IMPOSSIBLE";

	return 0;
}