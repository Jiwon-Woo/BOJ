#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	deque<int> cards;
	for (int i = 0; i < n; i++) {
		cards.push_back(i + 1);
	}

	while (cards.size() > 1) {
        cards.pop_front();
        cards.push_back(cards.front());
		cards.pop_front();
	}
	cout << cards.front();
	return 0;
}