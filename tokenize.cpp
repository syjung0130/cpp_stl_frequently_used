#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	const string cur_day = "2022:07:03";
	const string cur_time = "13:28:33";

	size_t n = 0;
	string token = ":";
	string day_buf = cur_day;
	//임시 string 변수에 현재 처리된 string을 저장해서 사용
	while ((n = day_buf.find(token)) != string::npos) {
		cout << day_buf.substr(0, n);
		day_buf = day_buf.substr(n+token.size());
	}
	cout << day_buf << endl;


	int idx = 0;
	vector<string> tokens;
	while ((n = cur_day.find(token, idx)) != string::npos) {
		//cout << cur_day.substr(idx, n-idx);
		tokens.push_back(cur_day.substr(idx, n-idx));
		idx = n + token.size();
		cout << "idx: " << idx 
			<< ", " << " size: " << cur_day.size() 
			<< ", " << " n: " << n
			<< ", " << " token size: " << token.size()
			<< endl;
	}
	tokens.push_back(cur_day.substr(idx+token.size()));

	cout << endl;
	for (auto s : tokens) {
		cout << s << ", ";
	}
	cout << endl;

	//string을 임시변수를 사용하지 않고 index를 기억해서 하는 방법

	return 0;
}
