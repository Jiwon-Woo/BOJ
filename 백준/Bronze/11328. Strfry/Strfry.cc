#include <iostream>

using namespace std;

bool ft_strfry(string s1, string s2) {
	int check[26] = {0, };

	if (s1.size() != s2.size()) {
		return false;
	}

	for (int i = 0; i < s1.size(); i++) {
		check[s1[i] - 'a']++;
	}

	for (int i = 0; i < s2.size(); i++) {
		if (check[s2[i] - 'a'] == 0) {
			return false;
		}
		check[s2[i] - 'a']--;
	}
	return true;
}

int main() {
	int n;
	string s1, s2;

	scanf("%d", &n);

	for (int i = 0; i < n; i ++) {
		cin >> s1 >> s2;
		if (ft_strfry(s1, s2)) {
			cout << "Possible\n";
		} else {
			cout << "Impossible\n";
		}
	}

	return 0;
}