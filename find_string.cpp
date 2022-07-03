#include <string>
#include <iostream>

using namespace std;

int main()
{
    size_t n;
    string const s = "This is a string";
 
    // search from beginning of string
    n = s.find("is");
    cout << "found: " << s.substr(n) << endl;
    // found: is is a string
 
    // search from position 5
    n = s.find("is", 5);
    cout << "found: " << s.substr(n) << endl;
    // found: is a string
 
    // find a single character
    n = s.find('a');
    cout << "found: " << s.substr(n) << endl;
    // found: a string
 
    // find a single character
    n = s.find('q');
    if (n == string::npos)
        cout << "not found character" << endl;
    else
        cout << "found: " << s.substr(n) << endl;
    //not found character
	
	return 0;
}
