#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	string s, command, c;
	int m;

	cin >> s;
	scanf("%d", &m);

	list<char> text;
	for (int i = 0; i < s.size(); i++) {
		text.push_back(s[i]);
	}
	list<char>::iterator cursor = text.end();

	for (int i = 0; i < m; i++) {
		cin >> command;
		if (command == "P") {
			cin >> c;
		}

		// cout << "before: ";
		// list<char>::iterator it;
		// for (it = text.begin(); it != text.end(); it++) {
		// 	if (it == cursor) {
		// 		cout <<"|";
		// 	}
		// 	cout << *it;
		// }
		// if (it == cursor) {
		// 	cout <<"|";
		// }
		// cout << "\n";

		switch (command[0])
		{
		case 'L':
			if (cursor != text.begin()) {
				cursor--;
			}
			break;
		case 'D':
			if (cursor != text.end()) {
				cursor++;
			}
			break;
		case 'B':
			if (cursor != text.begin()) {
				cursor = text.erase(--cursor);
			}
			break;
		case 'P':
			text.insert(cursor, c[0]);
			// cursor++;
			break;
		default:
			break;
		}

		// cout << "after: ";
		// for (it = text.begin(); it != text.end(); it++) {
		// 	if (it == cursor) {
		// 		cout <<"|";
		// 	}
		// 	cout << *it;
		// }
		// if (it == cursor) {
		// 	cout <<"|";
		// }
		// cout << "\n";
	}

	for (list<char>::iterator it = text.begin(); it != text.end(); it++) {
		cout << *it;
	}

	return 0;
}