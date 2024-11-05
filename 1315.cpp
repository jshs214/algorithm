#include <bits/stdc++.h>
using namespace std;

struct QUEST {
	int _str;
	int _int;
	int _pnt;
};

vector<QUEST> a;
int visited[55];

int dp[1004][1004];
int n;

int solve(int STR, int INT) {
	int& ret = dp[STR][INT];
	if (ret != -1) return ret;

	ret = 0;
	int pnt = 0;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		if (a[i]._str <= STR || a[i]._int <= INT) {
			ret++;

			if (!visited[i]) {
				visited[i] = true;
				pnt += a[i]._pnt;
				v.push_back(i);
			}

		}
	}

	for (int i = 0; i <= pnt; i++) {
		int next_STR = min(1000, STR+ i);
		int next_INT = min(1000, INT + pnt - i);

		ret = max(ret, solve(next_STR, next_INT));
	}

	for (auto i : v) {
		visited[i] = false;
	}


	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int st, in, pn;
		cin >> st >> in >> pn;

		a.push_back({ st, in, pn });
	}

	fill(&dp[0][0], &dp[0][0] + 1004 * 1004, -1);
	
	cout << solve(1, 1);

	return 0;
}