#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> a = {1, 4, 1, 2, 4, 2, 4, 2, 3, 4, 4};
	for (int i = 1; i <= 5; i++) {
		cout << i << ": " << count(a.begin(), a.end(), i) << endl;
	}

	int evenNumCount = count_if(a.begin(), a.end(), [=](int x){
		if (x%2 == 0) return true;
		else return false;
	});
	cout << "even num count: " << evenNumCount << endl;

	return 0;
}
