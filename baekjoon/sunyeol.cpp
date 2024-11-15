#include <bits/stdc++.h>

using namespace std;

vector<int> a = { 3,1,2 };
int n = 3, r = 3, depth = 0;

void print() {
	for (auto i : a) {
		cout << i << " ";
	}
	cout << "\n";
}
void makePermutation(int n, int r, int depth) {
	if (r == depth) {
		print();
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(a[i], a[depth]);
		makePermutation(n, r, depth + 1);
		swap(a[i], a[depth]);
	}
	return;
}
void main() {
	makePermutation(n, r, depth);
}