#include <bits/stdc++.h>
using namespace std;

int n, k;


int visited[100004];
int cnt[100004];

int main() {
	cin >> n >> k;
	
	if (n == k) {
		cout << 0 << "\n";
		cout << 1 << "\n";
		return 0;
	}

	queue<int> q;
	visited[n] = 1;
	cnt[n] = 1;
	q.push(n);

	while (q.size()) {
		int here = q.front();
		q.pop();

		for (int next : {here + 1, here - 1, here * 2}) {
			if (0 <= next && next <= 100000) {
				
				if (!visited[next]) {

					q.push(next);
					visited[next] = visited[here] + 1;
					cnt[next] += cnt[here];
				}
				else if (visited[next] == visited[here] +1)
					cnt[next] += cnt[here];

			}

		}
	}

	cout << visited[k] - 1 <<"\n" << cnt[k];


	return 0;
}