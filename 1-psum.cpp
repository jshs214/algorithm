#include <bits/stdc++.h>

using namespace std;

int  m, a, b;
int psum[100004];
int n[100004];

int main() {
	int cnt;
	cin >> cnt >> m;

	//prefix sum 의 idx 는 1부터 시작
	for (int i = 1; i <= cnt; i++) {
		cin >> n[i];
		psum[i] = n[i] + psum[i - 1];
	} 

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		cout << psum[b] - psum[a - 1] <<endl;
	}


	return 0;
}