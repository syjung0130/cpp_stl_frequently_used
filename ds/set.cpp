#include <set>
#include <iostream>

using namespace std;

int main() {
	int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};

	int n = sizeof(arr) / sizeof(int);
	cout << "n: " << n << endl;

	cout << "arr: ";
	for (auto d : arr)
		cout << d << ", ";
	cout << endl;

	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(i);
	}

	cout << "set: ";
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;

	return 0;
}
