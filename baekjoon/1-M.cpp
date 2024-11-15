#include <bits/stdc++.h>

using namespace std;

int ret = 0;
int n = 0;
string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		
		cin >> str;
		stack<char> s;
		
		for (int i = 0; i < str.length(); i++) {
			if (s.size() != 0 && s.top() == str[i])
				s.pop();
			else 
				s.push(str[i]);
		}
		if (s.size() == 0) ret++;
	}

	cout << ret;

	return 0;
}