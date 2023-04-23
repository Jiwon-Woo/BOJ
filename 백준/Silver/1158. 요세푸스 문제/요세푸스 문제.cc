#include <iostream>
#include <list>

using namespace std;

int main() {
	int n, k;
	list<int> people;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		people.push_back(i + 1);
	}

	list<int>::iterator pointer = people.begin();
	cout << '<';
	while (people.size()) {
		pointer--;
		for (int i = 0; i < k; i++) {
			pointer++;
			if (pointer == people.end()) {
				pointer = people.begin();
			}
		}
		cout << *pointer;
		pointer = people.erase(pointer);
		if (people.size()) {
			cout << ", ";
		}
	}
	cout << '>';

	return 0;
}