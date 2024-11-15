#include <bits/stdc++.h>
using namespace std;

int n;
int m;

int input;

void add() {
	cin >> input;
	n |= (1 << input);
}
void remove() {
	cin >> input;
	n &= ~(1 << input);
}
void check() {
	cin >> input;
	(n&(1<<input)) == 0? 0 : 1;
}

void toggle() {
	cin >> input;
	n ^= (1 << input);
}
void all() {
	n = (1 << 21) - 1;
}
void empty() {
	n = 0;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> m;
	
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s == "add")
			add();
		else if (s == "remove")
			remove();
		else if (s == "check")
			check();
		else if (s == "toggle")
			toggle();
		else if (s == "all")
			all();
		else if (s == "empty")
			empty();
	}
	return 0;
}