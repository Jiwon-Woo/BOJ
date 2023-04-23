#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k, n;
	stack<int> s;
	long answer = 0;

	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &n);
		if (n) {
			s.push(n);
		} else {
			s.pop();
		}
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}

	cout << answer << "\n";

	return 0;
}