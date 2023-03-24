#include <iostream>

using namespace std;

int num[201];
int main() {
	int n, v;
	int answer = 0;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		num[x + 100]++;
	}

	scanf("%d", &v);
	
	cout << num[v + 100];
	return 0;
}