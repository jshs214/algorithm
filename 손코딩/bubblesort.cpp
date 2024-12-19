#include <bits/stdc++.h>
using namespace std;

const int n = 10;
int a[n] = { 4,6,1,2,8,9,1,2,0 ,7 };

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	
	return 0;
}