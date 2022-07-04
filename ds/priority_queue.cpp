#include <queue>
#include <iostream>

using namespace std;

// https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

// priority_queue는 queue에서 front()로 맨 위의 원소를 조회하는 것과 달리,
// top()메서들ㄹ 사용해서 맨 앞의 원소를 조회한다.
void showpq(priority_queue<int> pq) {
	cout << endl;
	while (!pq.empty()) {
		cout << "\t" << pq.top();
		pq.pop();
	}
	cout << endl;
}

void showpq2(priority_queue<int, vector<int>, greater<int>> pq) {
	cout << endl;
	while (!pq.empty()) {
		cout << "\t" << pq.top();
		pq.pop();
	}
	cout << endl;
}

int main() {

	//일반적인 방법, default는 max heap임.
	priority_queue<int> pq;
	pq.push(10);
	pq.push(30);
	pq.push(20);
	pq.push(5);
	pq.push(1);

	cout << "The priority queue pq is : ";
	showpq(pq);

	cout << "q.size(): " << pq.size() << endl;
	cout << "q.top() : " << pq.top() << endl;
	cout << "q.pop() : ";
	pq.pop();
	showpq(pq);
	cout << endl;

	//min heap으로 생성하는 방법
	priority_queue<int, vector<int>, greater<int>> pq2;
	pq2.push(10);
	pq2.push(30);
	pq2.push(20);
	pq2.push(5);
	pq2.push(1);

	cout << "The priority queue pq2 size is: ";
	showpq2(pq2);

	cout << "pq2.size(): " << pq2.size() << endl;
	cout << "pq2.top() : " << pq2.top() << endl;
	cout << "pq2.pop() : ";

	pq2.pop();
	showpq2(pq2);
	cout << endl;


	//원소들에 -1을 곱해서 min heap으로 바꾸는 방법
	int arr[] = {1, 2, 3};
	int n = sizeof(arr) / sizeof(int);
	priority_queue<int> pq3(arr, arr+n);
	
	cout << "Max priority queue: ";
	while(!pq3.empty()) {
		cout << pq3.top() << " ";
		pq3.pop();
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		arr[i] = -arr[i];
	}
	
	priority_queue<int>	pq4(arr, arr+3);
	cout << "Min priority queue: ";
	while (pq4.empty() == false) {
		cout << -pq4.top() << " ";
		pq4.pop();
	}
	cout << endl;

	return 0;
}
