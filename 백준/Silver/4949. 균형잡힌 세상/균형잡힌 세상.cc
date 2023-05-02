#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> brackets;
	string line;

	getline(cin, line);
	while (line != ".") {
		for (char letter : line) {
			if (letter == '.') {
				cout << (brackets.empty() ? "yes\n": "no\n");
				while (!brackets.empty()) {
					brackets.pop();
				}
			} else if (letter == '(' || letter == '[') {
				brackets.push(letter);
			} else if (letter == ')') {
				!brackets.empty() && brackets.top() == '(' ? brackets.pop(): brackets.push(letter);
			} else if (letter == ']') {
				!brackets.empty() && brackets.top() == '[' ? brackets.pop(): brackets.push(letter);
			}
		}
		getline(cin, line);
	}

	return 0;
}