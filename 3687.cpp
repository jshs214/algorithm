#include <bits/stdc++.h>
using namespace std;

int a[10] = { 6,2,5,5,4,5,6,3,7,6 };
string dp[104], MAX_STR ="11111111111111111111111111111111111111111111111111111";
int t, n;

string get_min_str(string a, string b) {
	if (a.size() == b.size())
		return a > b ? a : b;
	if (a.size() < b.size()) return a;
	else return b;
}

string minSolve(int here) {
	if (here == 0) return "";

	string &ret = dp[here];
	if (ret != MAX_STR) return ret;

	for (int i = 0; i <= 9; i++) {
		if (here - a[i] < 0) continue;
		//첫째 자리에 0 이오면
		if (here == n && i == 0) continue;
		ret = get_min_str(ret, to_string(i) + minSolve(here - a[i]));

	} 
	return ret;
}

// Greedy
string maxSolve(int n) {
	string ret = "";

	if (n % 2 == 1) {
		ret += '7';
		n -= 3;
	}
	while (n) {
		ret += 1;
		n -= 2;
	}
	return ret;
}

int main() {

	cin >> t;
	while (t--) {
		cin >> n;
		fill(dp, dp + 104, MAX_STR);
		cout << minSolve(n) <<" " << maxSolve(n) << "\n";
	}

	

	return 0;
}