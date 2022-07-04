#include <stack>
#include <iostream>

using namespace std;

int main() {

	stack<int> s;
	s.push(21);
	s.push(22);
	s.push(23);
	s.push(24);
	s.push(25);

	s.pop();
	s.pop();

	cout << "stack: ";
	while (!s.empty()) {
		cout << s.top() << ", ";
		s.pop();
	}
	cout << endl;
	
	return 0;
}

