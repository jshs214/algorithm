#include <bits/stdc++.h>
using namespace std;

queue<char> q;
string s;
int main() {
	cin >> s;
	
	for (int i = 0; i < s.size(); i++) {
		q.push(s[i]);
	}

	
	string qStr;
	for (int i = 0; i < s.size(); i++) {
		qStr += q.front(); q.pop();

		if (qStr == "pi" || qStr == "ka" || qStr == "chu") {
			qStr.clear();
		}
	}

	if (qStr.empty()) cout << "YES";
	else cout << "NO";


	return 0;
}