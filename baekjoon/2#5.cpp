#include <bits/stdc++.h>

using namespace std;

vector<int> a[10];
bool visited[10];

void go(int from) {
	visited[from] = 1;
	cout << from << endl;

	for (int there : a[from]) {
		if (visited[there]) continue;
		go(there);
	}
	return;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	a[1].push_back(2); a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(1);  a[3].push_back(4);
	a[4].push_back(3);

	for (int i = 0; i < 10; i++) {
		if(a[i].size() && !visited[i])
			go(i);
	}

}

//1 2 2 1
//1 3 3 1
//3 4 4 3