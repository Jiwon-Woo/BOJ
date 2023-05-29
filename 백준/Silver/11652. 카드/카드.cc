#include <bits/stdc++.h>

using namespace std;

int n;
vector<long> cards;
int max_cnt = 0;
long value = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	while (n--) {
		long temp;
		cin >> temp;
		cards.push_back(temp);
	}
	sort(cards.begin(), cards.end());

	for (int i = 0; i < cards.size(); i++) {
		int cnt = 1;
		while (i + 1 < cards.size() && cards[i] == cards[i + 1]) {
			i++; cnt++;
		}
		if (max_cnt < cnt) {
			max_cnt = cnt;
			value = cards[i];
		}
	}
	cout << value;

	return 0;
}