#include <bits/stdc++.h>
using namespace std;

int idx = 0;
int a[100];

int pop() {
	if (idx == 0) {
		cout << "stack empty" << "\n";
		return -1;
	}

	idx--;
	return a[idx];
}
void push(int n) {
	a[idx] = n;
	idx++;
}

void Print() {
	for (int i = 0; i < idx; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";
}
int main() {

	push(2);
	push(3);
	Print();
	push(4);
	pop();
	Print();

	return 0;
}