#include <bits/stdc++.h>
using namespace std;

const int maxSize = 10004;
int a[maxSize];
int rear = 0, front = 0;

int pop() {
	if (front == rear) {
		cout << "queue empty" << "\n";
		return -1;
	}
	int ret = a[front];
	front++;
	return ret;
}
void push(int n) {
	a[rear] = n;
	rear++;
}

void Print() {
	for (int i = front; i < rear; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {

	push(1); push(2); push(3); push(4);
	Print();
	pop();
	Print();

	return 0;
}