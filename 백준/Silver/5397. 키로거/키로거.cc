#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	string s;
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		cin >> s;
		list<char> password;
		list<char>::iterator cursor = password.end();

		for (char c : s)
		{
			switch (c)
			{
			case '<':
				if (cursor != password.begin()) {
					cursor--;
				}
				break;
			case '>':
				if (cursor != password.end()) {
					cursor++;
				}
				break;
			case '-':
				if (cursor != password.begin()) {
					cursor = password.erase(--cursor);
				}
				break;
			default:
				password.insert(cursor, c);
				break;
			}
		}

		for (list<char>::iterator it = password.begin(); it != password.end(); it++) {
			cout << *it;
		}
		cout << '\n';
	}

	return 0;
}