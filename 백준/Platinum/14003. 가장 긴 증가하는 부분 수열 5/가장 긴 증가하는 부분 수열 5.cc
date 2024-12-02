#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000004];
int len = 0;

pair<int, int> ans[1000004];
stack<int> stk;

int main() {
	cin >> n;
	
	fill(a, a + 1000004, INT_MAX);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		auto lowerPos = lower_bound(a, a + len, num);
		int _pos = (int)(lowerPos - a);
		if (*lowerPos == INT_MAX) len++;
		*lowerPos = num;

		ans[i].first = _pos;
		ans[i].second = num;
	}

	cout << len <<'\n';

	for (int i = n - 1; i >= 0; i--) {
		if (ans[i].first == len- 1) {
			stk.push(ans[i].second);
			len--;
		}
	}

	while (stk.size()) {
		cout << stk.top()<<" ";
		stk.pop();
	}




	return 0;
}