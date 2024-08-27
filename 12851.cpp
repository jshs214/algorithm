#include <bits/stdc++.h>
using namespace std;


int visited[100004];
int cnt[100004];

queue<int> q;

int direction[3] = { -1, +1, 2 };
int ret = 987654321;

int n, k;


int main() {
	cin >> n >> k;

	visited[n] = 1;
	cnt[n] = 1;

	q.push(n);

	while (q.size()) {
		int here = q.front(); q.pop();

		for (int i = 0; i < 3; i++) {
			int there;
			if (i == 2)  there = here * direction[i];
			else  there = here + direction[i];

			// range check
			if (there < 0 || there > 100000) continue;

			if (!visited[there]) {
				q.push(there);
				visited[there] = visited[here] + 1;
				cnt[there] += cnt[here];
			}
			else if (visited[there] == visited[here] + 1) {
				cnt[there] += cnt[here];
			}
			
		}
	}

	cout << visited[k] - 1 << "\n" << cnt[k];

	return 0;
}