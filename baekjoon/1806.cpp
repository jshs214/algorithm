#include <bits/stdc++.h>
using namespace std;

int pSum[100005];

int n, s, ret = INT_MAX;

int main() {
	cin >> n >> s;

	bool exception = false;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		pSum[i] = pSum[i - 1] + num;
		if (num == s)
			exception = true;
	}

	if (exception) {
		cout << "1";
		return 0;
	}

	int start = 0, end = 1;

	while (end <= n) {
		int sum = pSum[end] - pSum[start];
		
		if (sum >= s) {
			ret = min(ret, end-start);	
			start++;
		}
		else if (sum < s) {
			end++;
		}
		
	}

	if (ret == INT_MAX)
		cout << "0";
	else
		cout << ret;

	return 0;
}