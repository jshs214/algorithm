#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll a[91];

ll fibo(ll num) {
	if (num == 0 || num == 1)
		return num;

	ll& ret = a[num];
	return ret = fibo(num - 1) + fibo(num - 2);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	
	cout << fibo(n);

	return 0;
}