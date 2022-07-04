#include <map>
#include <iostream>

using namespace std;

int main()
{

	map<int, int> m1;
	m1.insert(pair<int, int>(1, 40));
	m1.insert(pair<int, int>(2, 30));
	m1.insert(pair<int, int>(3, 60));
	m1.insert(pair<int, int>(4, 20));
	m1.insert(pair<int, int>(5, 50));
	m1.insert(pair<int, int>(6, 50));
	m1[7] = 10;

	map<int, int>::iterator it;
	cout << "The map m1 is: " << endl;
	cout << "\tKEY\tELEMENT" << endl;
	for (it = m1.begin(); it != m1.end(); ++it) {
		cout << "\t" << it->first << "\t" << it->second << endl;
	}
	cout << endl;

	//assigning the elements from m1 to m2.
	map<int, int> m2(m1.begin(), m1.end());
	//print all elements of the map m2
	cout << "The map m2 after assign from m1 is: " << endl;
	cout << "\tKEY\tELEMENT" << endl;
	for (it = m2.begin(); it != m2.end(); it++) {
		cout << "\t" << it->first << "\t" << it->second << endl;
	}
	cout << endl;

	//remove all elements with key = 4
	int num;
	num = m2.erase(4);
	cout << "m2.erase(4) : " << num << " removed" << endl;
	cout << "\tKEY\tELEMENT" << endl;
	for (it = m2.begin(); it != m2.end(); ++it) {
		cout << "\t" << it->first << "\t" << it->second << endl;
	}
	cout << endl;


	return 0;
}
