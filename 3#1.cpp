#include <bits/stdc++.h>

#if 0
// ½ÂÃ¶ÀÌ »¡°£±¸¸§
using namespace std;

int n, temp;
vector<int> v;

bool check(int n) {
	if (n == 1)	return 0;
	if (n == 2)	return 1;
	if (n % 2 == 0)	return 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)	return 0;
	}
	return 1;
}

int go(int idx, int sum) {
	if (idx == n)
		return check(sum);

	return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cout << go(0, 0) << "\n";

	return 0;
}
#endif

using namespace std;

int n, temp, ret;
vector<int> v;
const int mod = 11;


void go(int idx, int sum) {
	//if (ret == 10) return;
	if (idx == n) {
		ret = max(ret, sum % mod);
		return;
	}
	go(idx + 1, sum + v[idx]);
	go(idx + 1, sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	go(0, 0);
	cout << ret << "\n";



}