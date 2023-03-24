#include <iostream>

using namespace std;

int make_anagram(string s1, string s2) {
	int s1_check[26] = {0, };
	int s2_check[26] = {0, };
	int answer = 0;

	for (int i = 0; i < s1.size(); i++) {
		s1_check[s1[i] - 'a']++;
	}
	for (int i = 0; i < s2.size(); i++) {
		s2_check[s2[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		answer += abs(s1_check[i] - s2_check[i]);
	}
	return answer;
}

int main() {
	int n;
	string s1, s2;

	cin >> s1 >> s2;
	cout << make_anagram(s1, s2);
}