//성주는 ㅄ이니까 다시풀어야함 꼭
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int temp;
//int psum[100001];
//
//int n, k;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> n >> k;
//	
//	for (int i = 1; i <= n; i++) {
//		cin >> temp;
//		
//		psum[i] = temp + psum[i - 1];
//;
//	}
//	
//	int ret = -122222222;
//
//	//i :  2 ~ 10
//	for (int i = k; i <= n; i++) {
//		int value = psum[i] - psum[i - k];
//		ret = max(ret, value);
//	}
//
//	cout << ret << endl;
//
//	return 0;
//}

#include <bits/stdc++.h>

using namespace std;

int psum[100003];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int k = 1; k <= n; k++) {
		int temp;
		cin >> temp;
		psum[k] = temp + psum[k - 1];
	}


	for (int k = 0; k < m; k++) {
		int i, j;
		cin >> i >> j;
		cout << psum[j] - psum[i - 1]<<"\n";
	}

	
	return 0;
}