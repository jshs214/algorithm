#include <bits/stdc++.h>
using namespace std;

vector<string> v;

char op[10];
int visited[10];
int k;

bool check(char x, char y, char op) {
	if (op == '>')
		if (x > y)
			return true;
	if (op == '<')
		if (x < y)
			return true;

	return false;
}

void go(int idx, string num) {
	if (idx == k + 1) {
		v.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (visited[i]) continue;

		if (idx == 0) {
			visited[i] = 1;
			go(idx + 1, num + to_string(i) );
			visited[i] = 0;
		}
		else if ( check(num[idx - 1], i + '0', op[idx-1])) {
			visited[i] = 1;
			
			go(idx + 1, num + to_string(i) );
			visited[i] = 0;
		}
	}


}


int main() {
	cin >> k;

	for (int i = 0; i < k; i++)
		cin >> op[i];

	go(0, "");
	
	sort(v.begin(), v.end());

	cout << v[v.size() -1] << "\n" << v[0];
		
	return 0;
}