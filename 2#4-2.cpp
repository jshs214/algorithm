#include <bits/stdc++.h>
#include <stdbool.h>

using namespace std;

bool a[10][10];
bool visited[10];

void go(int from) {
	visited[from] = 1;
	cout << from << endl;

	for (int i = 0; i < 10; i++) {
		if (visited[i])	continue;
		if (a[from][i]) {
			go(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	a[1][2] = 1;
	a[2][1] = 1;
	a[1][3] = 1;
	a[3][1] = 1;
	a[3][4] = 1;
	a[4][3] = 1;


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i][j] && !visited[i]) {
				go(i);
			}
		}
	}
}