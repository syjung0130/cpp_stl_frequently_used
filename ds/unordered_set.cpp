#include <unordered_set>
#include <iostream>

using namespace std;

/*
// https://www.geeksforgeeks.org/unordered_set-in-cpp-stl/
## Sets vs Unordered Sets 
Set is an ordered sequence of unique keys whereas unordered_set is a set in which key can be stored in any order, so unordered. 
Set is implemented as a balanced tree structure that is why it is possible to maintain order between the elements (by specific tree traversal). 
The time complexity of set operations is O(log n) while for unordered_set, it is O(1). 

## Methods on Unordered Sets: 
For unordered_set many functions are defined among which most used are the size and empty for capacity, 
 find for searching a key, insert and erase for modification. 
The Unordered_set allows only unique keys, for duplicate keys unordered_multiset should be used. 
Example of declaration, find, insert and iteration in unordered_set is given below :
*/

int main() {
	int arr[] = {1, 5, 2, 1, 4, 3, 1, 7, 2, 8, 9, 5};

	int n = sizeof(arr) / sizeof(int);
	cout << "n: " << n << endl;

	cout << "arr: ";
	for (auto d : arr)
		cout << d << ", ";
	cout << endl;

	unordered_set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(i);
	}

	cout << "unordered_set: ";
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl;

	return 0;
}
