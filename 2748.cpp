#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll a[94];

ll fibo(ll num) {
	if (num == 0 || num == 1)
		return num;

	ll& ret = a[num];
	return ret = fibo(num - 1) + fibo(num - 2);
}


int main() {
	cin >> n;
	
	cout << fibo(n);

	return 0;
}