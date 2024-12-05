#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[104];
int num;
int main() {
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	a[6] = 3;
	
	for (int i = 7; i <= 100; i++) {
		a[i] = a[i - 1] + a[i - 5];
	}
	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> num;
		cout << a[num] << "\n";
	}

	return 0;
}