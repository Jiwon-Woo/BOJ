#include <iostream>

using namespace std;

int room[7][2];

int main() {
	int n, k, s, y;
	int answer = 0;
	
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s, &y);
		room[y][s]++;
	}

	for (int i = 1; i < 7; i++) {
		for (int j = 0; j < 2; j++) {
			answer += room[i][j] / k;
			answer += room[i][j] % k > 0 ? 1 : 0;
		}
	}
	
	cout << answer;
	return 0;
}