#include <string>
#include <iostream>

using namespace std;

int main()
{
	string a = "0123456789abcdefghij";
	
	string sub1 = a.substr(10);//index가 10인 위치부터의 문자열을 리턴.
	cout << sub1 << endl;
	//출력: abcdefghij

	string sub2 = a.substr(5, 3);//index가 5인 위치부터의 길이가 3인 문자열을 리턴.
	cout << sub2 << endl;
	//출력: 567

	//index가 끝에서 문자열 끝에서 3번째 전의 위치부터 문자열 끝까지의 문자열을 리턴
	//substr내부에서 길이가 문자열 범위를 벗어날 경우, 문자열 끝까지만 리턴하도록 처리함.
	string sub4 = a.substr(a.size()-3, 50);
	cout << sub4 << endl;
	//출력: hij

	return 0;
}
