#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (scanf("%d", &n) != EOF ) {
		int cnt = 1;
		int ret=1;
		 
		while (1) {
			if (cnt % n == 0) {
				cout << ret<<"\n";
				break;
			}
			else {
				cnt = cnt * 10 + 1;
				cnt %= n;
				ret++;
			}
		}

	}

}