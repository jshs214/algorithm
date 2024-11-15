#include <bits/stdc++.h>
using namespace std;

int n, k;

int visited[200004];
int prevVisited[200004];
queue<int> q;

int ret;

int main() {
	cin >> n >> k;

	q.push(n);
	visited[n] = 1;
	while (q.size()) {
		int here = q.front(); q.pop();

		if (here == k) {
			ret = visited[k];
			break;
		}
		for (int there : {here + 1, here - 1, here * 2}) {

			if (there < 0 || there >= 200004) continue;
			if (visited[there]) continue;

			visited[there] = visited[here] +1;
			prevVisited[there] = here;
			q.push(there);
		}
	}

	

	vector<int> v;
	for (int i = k; i != n; i = prevVisited[i]) {
		v.push_back(i);
	}
	v.push_back(n);
	

	cout << visited[k] - 1<<"\n";
	for (auto i : v)
		cout << i << " ";

	return 0;
}