#include <string>
#include <iostream>

using namespace std;

int main() {
	size_t n;
	string const s = "This is a string";

	n = s.find("is");
	cout << "found: " << s.substr(n) << endl;

	n = s.find("is", 5);
	cout << "found: " << s.substr(n) << endl;

	n = s.find('a');
	cout << "found: " << s.substr(n) << endl;

	n = s.find('q');
	if (n == string::npos)
		cout << "not found character" << endl;
	else
		cout << "found: " << s.substr(n) << endl;

	return 0;
}
