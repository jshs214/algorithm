#include <bits/stdc++.h>
using namespace std;

const int n = 10;
int a[n] = { 4,6,1,2,8,9,1,2,0 ,7 };

int main() {
	for (int i = 1; i < n; i++) {
		int tmp = a[i];
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > tmp) {
				a[j + 1] = a[j];
				a[j] = tmp;
			}
			else break;
		}
	}



	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	
	return 0;
}