#include <bits/stdc++.h>
using namespace std;

int n, m, c;

int a[22];
// 가방 수, 보석 가져가는 경우의 수,  최대 무게
int dp[22][1<<14][22];

int solve(int here, int useJewel, int weight) {
	if (here == m) return 0;

	int& ret = dp[here][useJewel][weight];
	if (ret) return ret;

	ret = max(ret, solve(here + 1, useJewel, c));

	// 보석 순회
	for(int i = 0; i <n; i++){
		// 보석 사용 check(비트마스킹)
		bool isBeforeUse = (1 << i) & useJewel;
		// 현재 남은 무게에 보석이 되는지
		bool isCan = (weight - a[i]) >= 0;
		
		if (!isBeforeUse && isCan)
			ret = max(ret, solve(here, (1 << i) | useJewel, weight - a[i]) + 1);

	}

	return ret;
}

int main(){
	// 보석 수, 가방 수, 가방 別 무게
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(dp, 0, sizeof(dp));
	
	cout << solve(0, 0, c);

	return 0;
}