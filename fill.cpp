#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
	cout << "before fill: ";
	for (auto d : a)
		cout << d << ", ";
	cout << endl;

	cout << "after fill : ";
	fill(a.begin(), a.end(), 0);
	for (auto d : a)
		cout << d << ", ";
	cout << endl;

	return 0;
}
