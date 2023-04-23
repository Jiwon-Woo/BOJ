#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n, t;
	vector<int> towers;
	stack<int> temp;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		towers.push_back(t);
	}
	
	for (int i = 0; i < towers.size(); i++) {
		while (temp.size() && towers[temp.top() - 1] < towers[i]) {
			temp.pop();
		}
		if (temp.size()) {
			cout << temp.top() << " ";
		} else {
			cout << 0 << " ";
		}
		temp.push(i + 1);
	}

	return 0;
}