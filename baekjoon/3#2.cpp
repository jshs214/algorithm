#include <bits/stdc++.h>

using namespace std;

int visited[4];
vector<int> adj[4];
vector<int> v;

int main() {
	adj[0].push_back(0);
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[1].push_back(0);
	adj[2].push_back(1);
	adj[3].push_back(1);

	visited[0] = 1;
	v.push_back(0);


	return 0;
}