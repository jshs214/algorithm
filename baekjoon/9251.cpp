#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1004][1004];

int main() {
	cin >> s1 >> s2;
	
	dp[0][0] = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			//INDEX ����
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[s1.size()][s2.size()];
	
	return 0;
}