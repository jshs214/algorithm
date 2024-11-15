#include <bits/stdc++.h>
using namespace std;


int t;
int n;

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;

		int ret2 = 0, ret5 = 0;

		for (int j = 2; j <= n; j *= 2){
			ret2 += n / j;
		}
		for (int j = 5; j <= n; j *= 5) {
			ret5 += n / j;
		}
		cout << ret5 << "\n";


	}
	
	return 0;
}