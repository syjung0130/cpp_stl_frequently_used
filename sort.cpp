#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
	int n = 0;
	vector<pair<int, int>> a = { {1, 3}, {7, 5}, {5, 2}, {3, 7} };

	cout << "before sort: {";
	for (auto p : a) {
		cout << "{" << p.first << ", " << p.second << "}, ";
	}
	cout << endl;

	sort(a.begin(), a.end(), 
		[=](pair<int, int> p1, pair<int, int> p2) {
			if (p1.first < p2.first) 
				return true;
			else 
				return false;
		});

	cout << "after lambda sort: {";
	for (auto p : a) {
		cout << "{" << p.first << ", " << p.second << "}, ";
	}
	cout << endl;

	sort(a.begin(), a.end(), greater<pair<int, int>>());
	cout << "after greater sort: {";
	for (auto p : a) {
		cout << "{" << p.first << ", " << p.second << "}, ";
	}
	cout << endl;


	return 0;
}