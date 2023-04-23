#include <iostream>
#include <stack>
#include <deque>
#include <vector>

using namespace std;

int main() {
	int n, m;
	stack<int> temp, my_seq;
	deque<int> seq;
	vector<char> answer;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		seq.push_back(m);
	}
	
	for (int i = 0; i < n; i++) {
		temp.push(i + 1);
		answer.push_back('+');
		while (temp.size() && seq.size() && temp.top() == seq.front()) {
			my_seq.push(temp.top());
			temp.pop();
			seq.pop_front();
			answer.push_back('-');
		}
	}
	if (temp.size()) {
		cout << "NO";
	} else {
		for (char a : answer)
		{
			cout << a << "\n";
		}
	}

	return 0;
}
