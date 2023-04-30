#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

deque<string> split(string origin, char delim) {
	istringstream iss(origin);
	string buf;
	deque<string> words;

	while (getline(iss, buf, delim)) {
		words.push_back(buf);
	}
	return words;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		string p, x;
		int n;
		deque<string> arr;

		cin >> p >> n >> x;
		arr = split(x.substr(1, x.size() - 2), ',');

		int flag = 1;
		int error = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'D') {
				if (arr.empty()) {
					error = 1;
					break;
				} else if (flag == 1) {
					arr.pop_front();
				} else if (flag == -1) {
					arr.pop_back();
				}
			} else if (p[i] == 'R') {
				flag *= -1;
			}
		}
		
		if (error) {
			cout << "error\n";
		} else if (flag == 1){
			cout << "[";
			for (int i = 0; i < arr.size(); i++)
			{
				if (i > 0) {
					cout << ",";
				}
				cout << arr[i];
			}
			cout << "]\n";
		} else if (flag == -1) {
			cout << "[";
			for (int i = arr.size() - 1; i > -1; i--)
			{
				cout << arr[i];
				if (i > 0) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}