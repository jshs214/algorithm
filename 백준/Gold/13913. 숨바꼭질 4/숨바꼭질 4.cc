#include <bits/stdc++.h>
using namespace std;

#define prev ddd

int n, k;

int visited[200004];
int prev[200004];
int main() {
	cin >> n >> k;

	queue<int> q;
	visited[n] = 1;
	q.push(n);

	while (q.size()) {
		int here = q.front();
		q.pop();

		for (int next : {here + 1, here - 1, here * 2}) {
			if (0 <= next && next <= 200004) {
				if (visited[next]) continue;
				
				visited[next] = visited[here] + 1;
				q.push(next);
				prev[next] = here;
			}

		}
	}

	

	vector<int> v;
	for (int i = k; i != n; i = prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);

	reverse(v.begin(), v.end());

	cout << visited[k] - 1<<"\n";
	for (auto i : v)
		cout << i << " ";

	return 0;
}