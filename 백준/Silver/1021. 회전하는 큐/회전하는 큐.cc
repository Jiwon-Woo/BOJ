#include <iostream>
#include <deque>

using namespace std;

int push_left(deque<int> &deq, deque<int>::iterator current, int goal) {
	int count = 0;

	while (*current != goal) {
		current++; count++;
		if (current == deq.end()) {
			current = deq.begin();
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	deque<int> deq;
	for (int i = 0; i < n; i++) {
		deq.push_back(i + 1);
	}
	deque<int>::iterator cursor = deq.begin();

	int answer = 0;
	for (int i = 0; i < m; i++)
	{
		int pos;
		cin >> pos;

		int left = push_left(deq, cursor, pos);
		int right = (int)deq.size() - left;
		if (left <= right) {
			answer += left;
			while (left--) {
				cursor++;
				if (cursor == deq.end()) {
					cursor = deq.begin();
				}
			}
		} else {
			answer += right;
			while (right--) {
				if (cursor == deq.begin()) {
					cursor = deq.end() - 1;
				} else {
					cursor--;
				}
			}
		}
		
		cursor = deq.erase(cursor);
		if (cursor == deq.end()) {
			cursor = deq.begin();
		}
	}
	std::cout << answer;
	return 0;
}