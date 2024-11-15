#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1004];
int visited[1004];

void postOrder(int idx)
{
	if (visited[idx] == 0) {
		if (adj[idx].size() == 1) postOrder( adj[idx][0]);
		if (adj[idx].size() == 2) {
			postOrder(adj[idx][0]);		// node->left
			postOrder(adj[idx][1]);		// node->right
		}
		visited[idx] = 1;
		cout << idx << " ";
	}
}

void preOrder(int idx)
{
	if (visited[idx] == 0) {
		visited[idx] = 1;
		cout << idx << " ";
		if (adj[idx].size() == 1) postOrder(adj[idx][0]);
		if (adj[idx].size() == 2) {
			postOrder(adj[idx][0]);		// node->left
			postOrder(adj[idx][1]);		// node->right
		}
	}
}
void inOrder(int idx) {
	if (visited[idx] == 0) {
		if (adj[idx].size() == 1) {
			inOrder(adj[idx][0]);
			visited[idx] = 1;
			cout << idx << " ";
		}
		else if (adj[idx].size() == 2) {
			inOrder(adj[idx][0]);
			visited[idx] = 1;
			cout << idx << " ";
			inOrder(adj[idx][1]);
		}
		else{
			visited[idx] = 1;
			cout << idx << " ";
		}
	}
	
}

int main()
{
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);

	int root = 1;


	return 0;
}