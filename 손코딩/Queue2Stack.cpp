//2개의 큐로 스택 구현
#include <bits/stdc++.h>
using namespace std;

queue<int> queue1, queue2;

void enqueue(int n) {
	queue1.push(n);
	return;
}
int dequeue() {
	while (queue1.size() > 1) {
		int tmp = queue1.front();
		queue1.pop();
		queue2.push(tmp);
	}

	int ret = queue1.front();
	queue1.pop();

	queue1 = queue2;
	return ret;
}
int main() {

	enqueue(4);
	enqueue(5);
	enqueue(6);

	cout << dequeue();
	cout << dequeue();
	cout << dequeue();

	return 0;
}