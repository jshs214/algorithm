#include <bits/stdc++.h>
using namespace std;

const int firstStep = 5;

int n;
vector<int> v;
int dp[6][6][100004];

int check(int n1, int n2) {
	// 초기에는 힘 2 반환
	if (n1 == firstStep) return 2;
	// 같은 곳 힘 1
	if (n1 == n2) return 1;
	// 반대 힘 4
	if (abs(n1 - n2) == 2) return 4;
	//인접 힘 3
	return 3;
}

int go(int left, int right, int idx) {
	if (idx == v.size()) 
		return 0;

	int& ret = dp[left][right][idx];
	if (ret != -1) return ret;

	int l = go(v[idx], right, idx + 1) + check(left, v[idx]);
	int r = go(left, v[idx], idx + 1) + check(right, v[idx]);
	
	ret = min(l, r);

	return ret;
}

int main() {
	while (true) {
		int temp;
		cin >> temp;
		if (temp == 0) break;
		
		v.push_back(temp);
	}

	//fill(&dp[0][0][0], &dp[0][0][0] + 6 * 6 * 100004, -1);

	memset(dp, -1, sizeof(dp));

	// 초기값 5
	cout << go(firstStep, firstStep, 0);

	return 0;
}