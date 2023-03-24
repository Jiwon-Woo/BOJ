#include <iostream>
#include <string>

using namespace std;

const int NUM = 10;
int check[NUM];
int main() {
	int num;
	int set = 0;

	cin >> num;

	int share = num;
	while(share > 0) {
		int res = share % 10;
		if (res == 6 || res == 9) {
			check[6] > check[9] ? check[9]++ : check[6]++;
			set = max(check[6] > check[9] ? check[6] : check[9], set);
		} else {
			check[res]++;
			set = max(check[res], set);
		}
		share = share / 10;
	}
	cout << set;
	return 0;
}