#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int visited[10001];
int dp[10001];
int ret = 0;

int n, m;
int a, b;

int dfs(int here) {
	int cnt = 1;
	visited[here] = 1;

	for (int there : v[here]) {
		if (visited[there]) continue;
		cnt+= dfs(there);
	}


	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}


	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		dp[i] = dfs(i);
		ret = max(ret, dp[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (ret == dp[i])
			cout << i << " ";
	}



	return 0;
}