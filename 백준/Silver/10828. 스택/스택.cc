#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	stack<int> s;
	string command;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		cin >> command;
		if (command == "pop") {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			} else {
				cout << -1 << '\n';
			}
		} else if (command == "size") {
			cout << s.size() << '\n';
		} else if (command == "empty") {
			cout << (s.empty() ? 1 : 0) << '\n';
		} else if (command == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		} else if (command == "push") {
			int num;
			scanf("%d", &num);
			s.push(num);
		}
	}

	return 0;
}