#include <bits/stdc++.h>
using namespace std;

int dist[404][404];
int n, m;
int a, b;
int tc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		dist[a][b] = -1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] == -1 && dist[k][j] == -1)
					dist[i][j] = -1;
				else if (dist[i][k] == 1 && dist[k][j] == 1)
					dist[i][j] = 1;
			}
		}
	}

	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		cout << dist[a][b] << "\n";
	}

	return 0;
}