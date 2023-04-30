#include <deque>
#include <iostream>

using namespace std;

int main() {
	int n;
	string command;
	deque<int> d;

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while (n--) {
		cin >> command;
		if (command == "push_back") {
			int element;
			cin >> element;
			d.push_back(element);
		} else if (command == "push_front") {
			int element;
			cin >> element;
			d.push_front(element);
		} else if (command == "pop_back") {
			if (d.empty()) {
				cout << "-1\n";
			} else {
				cout << d.back() << "\n";
				d.pop_back();
			}
		} else if (command == "pop_front") {
			if (d.empty()) {
				cout << "-1\n";
			} else {
				cout << d.front() << "\n";
				d.pop_front();
			}
		} else if (command == "size") {
			cout << d.size() << "\n";
		} else if (command == "empty") {
			cout << (d.empty() ? "1\n" : "0\n");
		} else if (command == "front") {
			cout << (d.empty() ? -1 : d.front()) << "\n";
		} else if (command == "back") {
			cout << (d.empty() ? -1 : d.back()) << "\n";
		}
	}

	return 0;
}