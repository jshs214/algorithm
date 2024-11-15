#include <bits/stdc++.h>
using namespace std;

int a[22][22];
int visited[22];

int n;
int minValue = INT_MAX;


void solve(int idx, int count) {
	if (count == n / 2) {
		int startTeam = 0, linkTeam = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i] && visited[j])
					startTeam += a[i][j];
				else if (!visited[i] && !visited[j])
					linkTeam += a[i][j];
			}
		}
		minValue = min(minValue, abs(startTeam - linkTeam));

		return;
	}

	for (int i = idx; i < n; i++) {
		visited[i] = 1;
		solve(i + 1, count + 1);
		visited[i] = 0;
	}
}
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	solve(0, 0);

	cout << minValue;

	return 0;
}