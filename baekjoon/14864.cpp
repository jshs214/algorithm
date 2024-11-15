#include <bits/stdc++.h>

using namespace std;

int n, m;

int a[100005], visited[100005];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int  s1, s2;
		cin >> s1 >> s2;
		a[s1]++; a[s2]--;
	}

	for (int i = 1; i <= n; i++) {
		a[i]+= i;
		visited[a[i]]++;
	}

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (visited[i] >= 2)flag = 1;
	}
	if (flag) cout << -1 << "\n";
	else {
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
	}


	return 0;
}