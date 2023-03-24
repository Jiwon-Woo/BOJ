#include <iostream>

using namespace std;

bool num[1000001];
int main() {
	int n, x;
	int answer = 0;
	
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &x);

	for (int i = 0; i < n; i++) {
		if (x - arr[i] > 0 && x - arr[i] < 2000000 && num[x - arr[i]]) {
			answer++;
		}
		num[arr[i]] = true;
	}
	cout << answer;
}