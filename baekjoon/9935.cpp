#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
string s;
string r;

int main() {
	cin >> s >> r;

	for (char i : s) {

		stk.push(i);
		if (stk.size() >= r.size() && stk.top() == r[r.size() - 1]) {
			string ss ="";
			for (int i : r) {
				ss += stk.top();
				stk.pop();
			}

			reverse(ss.begin(), ss.end());
			if (r != ss) {
				for (int i : ss)
					stk.push(i);
			}
		}
	}

	string ret;
	if (stk.size() == 0)
		cout << "FRULA";
	else {
		while (stk.size()) {
			ret += stk.top();
			stk.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret;
	}

	
	return 0;
}


