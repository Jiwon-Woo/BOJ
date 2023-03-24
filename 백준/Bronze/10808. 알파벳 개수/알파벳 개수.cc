#include <iostream>

using namespace std;

const int ALPHABET = 26;
int check[ALPHABET];
int main() {
	string s;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		check[s[i] - 'a']++;
	}
	cout << check[0];
	for (int i = 1; i < ALPHABET; i++) {
		cout << ' ' << check[i];
	}
	return 0;
}