#include <iostream>
#include <deque>

using namespace std;

int n, k;
int hide_and_seek[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	int sec = 0;
	deque<int> pos;
	pos.push_back(n);
	int asap = 100000;

	while (!pos.empty() && sec <= abs(n - k))
	{
		int len = pos.size();
		for (int i = 0; i < len; i++)
		{
			int curr = pos.front();
			pos.pop_front();

			if (k - curr == 0)
			{
				asap = min(asap, sec);
			}
			else
			{
				if (curr + 1 <= 200000 && !hide_and_seek[curr + 1])
				{
					pos.push_back(curr + 1);
					hide_and_seek[curr + 1] = 1;
				}
				if (curr * 2 <= 200000 && !hide_and_seek[curr * 2])
				{
					pos.push_back(curr * 2);
					hide_and_seek[curr * 2] = 1;
				}
				if (curr - 1 >= 0 && !hide_and_seek[curr - 1])
				{
					pos.push_back(curr - 1);
					hide_and_seek[curr - 1] = 1;
				}
			}
		}
		sec++;
	}

	cout << asap;

	return 0;
}