#include<bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, a[44], ret = INF;
string s;

void go(int here) {
	// n행 까지 탐색 마치면 종료 LOOP
	if (here == n + 1) {
		int sum = 0;

		//각 비트 위치를 순차적으로 확인하는 for
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (i & a[j]) 
					cnt++;

				sum += min(cnt, n - cnt);
			}
		}
		ret = min(ret, sum);
		return;
	}
	go(here + 1);
	a[here] = ~a[here];
	go(here + 1);
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'T')
				a[i] |= value;
			value *= 2;
		}
		cout << a[i] << " ";
		cout << endl;
	}

	go(1);

	cout << ret;



	return 0;
}