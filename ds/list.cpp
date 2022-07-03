#include <list>
#include <iostream>

using namespace std;

int main()
{
	list<int> l= {1, 5, 3, 7, 9};
	
	cout << "before         , list : ";
	for (auto d: l)
		cout << d << ", ";
	cout << endl;
	
	cout << "after push back, list : ";
	l.push_back(11);
	for (auto d: l)
		cout << d << ", ";
	cout << endl;
	
	cout << "after push front, list: ";
	l.push_front(99);
	for (auto d: l)
		cout << d << ", ";
	cout << endl;
	
	cout << "front: " << l.front() << endl;
	cout << "back : " << l.back() << endl;
	
	return 0;
}