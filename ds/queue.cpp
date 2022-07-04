#include <queue>
#include <iostream>

using namespace std;

void showq(queue<int> q)
{
	cout << endl;
	while (!q.empty()) {
		cout << "\t" << q.front();
		q.pop();
	}
	cout << endl;
}


int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);

	cout << "The queue q is: ";
#if 0
	while (!q.empty()) {
		cout << "\t" << q.front();
		q.pop();
	}
	cout << endl;
#else
	showq(q);
#endif
	cout << "q size() : " << q.size() << endl;
	cout << "q front(): " << q.front() << endl;
	cout << "q back() : " << q.back() << endl;

	cout << "q.pop(): " << q.front();
	q.pop();
	showq(q);

	return 0;
}
