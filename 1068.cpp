#include <bits/stdc++.h>
using namespace std;

int n, root;
vector<int> adj[55];
int removeNode;

int dfs(int here) {
	int ret = 0;
	int child = 0;

	for (int there : adj[here]) {
		if (there == removeNode)	continue;
		ret += dfs(there);
		child++;
	}
	if (child == 0)
		return 1;


	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int parents;
		cin >> parents;

		if (parents == -1) root = i;
		else adj[parents].push_back(i);
	}

	cin >> removeNode;
	if (removeNode == root)	cout << "0";
	else cout << dfs(root);

	return 0;
}