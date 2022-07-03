#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<int> v1 = {1, 3, 7, 5, 9};
	vector<pair<int, char>> v2;
	
	v1.push_back(5);
	v1.push_back(6);
	for (int i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	cout << "front: " << v1.front() << endl;
	cout << "rear : " << v1.back() << endl;
	
	cout << "after pop_back: ";
	v1.pop_back();
	for (auto d : v1)
		cout << d << ", ";
	cout << endl;
	
	cout << "after pop_front: ";
	//v1.pop_front();
	for (auto d: v1)
		cout << d << ", ";
	cout << endl;
	
	v1.insert(v1.begin(), 5);
	cout << "after insert to begin, front: " << v1.front() << endl;
	
	v1.erase(v1.begin());
	cout << "after erase begin, front: " << v1.front() << endl;
	
	v1.emplace(v1.begin(), 5);
	cout << "after emplace to begin, front: " << v1.front() << endl;
	
	v1.emplace_back(20);
	cout << "The last element is: " << v1[v1.size()-1] << endl;

	cout << "cur vector: ";
	//v1.pop_front();
	for (auto d: v1)
		cout << d << ", ";
	cout << endl;

	v1.clear();
	cout << "vector size after clear: " << v1.size() << endl;


	/*
	* Emplace takes the arguments necessary to construct an object in place, whereas insert takes (a reference to) an object.
	* emplace와 insert의 차이
	* emplace는 바로 생성이 된다.
	* insert는 object를 넘겨줘야지만 된다.
	*/
	//https://stackoverflow.com/questions/14788261/c-stdvector-emplace-vs-insert
	typedef struct Foo
	{
		public:
		Foo(int n, double x) {this->n = n; this->x = x;}
		int getN() {return this->n;};
		double getX() {return this->x;};
		private:
		int n = 0;
		double x = 0;
	}Foo;
	vector<Foo> v;
	v.emplace(v.begin(), 42, 3.1416);
	v.insert(v.begin(), Foo(42, 3.1416));

	for (auto st : v)
		cout << "{n: " << st.getN() << ", x: " << st.getX() << "}, ";
	cout << endl;

	return 0;
}