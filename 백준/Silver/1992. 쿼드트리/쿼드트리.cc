#include <bits/stdc++.h>
using namespace std;

int dist[64][64], n;

bool check(int y, int x, int siz) {
	int checknum = dist[y][x];

	for (int i = y; i < y + siz; i++) {
		for (int j = x; j < x + siz; j++) {
			if (checknum != dist[i][j])
				return false;
		}
	}
	

	return true;
}

void go(int y, int x, int siz) {
	if (check(y, x, siz)) {
		cout << dist[y][x];
		return;
	}

	cout << "(";  
	int half = siz / 2;
	go(y, x, half);                 
	go(y, x + half, half);          
	go(y + half, x, half);          
	go(y + half, x + half, half);   
	cout << ")"; 
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			dist[i][j] = s[j] -'0';
		}
	}

	go(0, 0, n );


	return 0;
}