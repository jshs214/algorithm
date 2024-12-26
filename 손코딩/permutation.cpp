#include <bits/stdc++.h>
using namespace std;

int a[] = { 1, 2, 3};
int n, r, depth;

void permu(int n, int r, int depth) {
	if (r == depth) {
		for (int i = 0; i < r; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = depth; i <= n; i++) {
		swap(a[i], a[depth]);
		permu(n, r, depth+1);
		swap(a[i], a[depth]);
	}
	return;
}

int main() {
	permu(3, 3, 0);
	
	return 0;
}