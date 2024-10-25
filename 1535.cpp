#include <bits/stdc++.h>
using namespace std;

const int maxhp = 100;

int n;
int hp[22];
int happy[22];
int dp[104];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> hp[i];
	for (int i = 0; i < n; i++)
		cin >> happy[i];


	for (int i = 0; i < n; i++) {
		for (int j = maxhp; j > hp[i]; j--) {
			dp[j] = max(dp[j], dp[j - hp[i]] + happy[i]);
		}
	}

	cout << dp[100];


	return 0;
}