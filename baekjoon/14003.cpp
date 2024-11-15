#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int length = 1000004;

int lis[length];
int n, len = 0;

// pos, num
pair<int, int> ans[length];
stack<int> stk;

int main() {
	cin >> n;

	fill(lis, lis + length, INT_MAX);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		auto lowerPos = lower_bound(lis, lis + len, num);
		int _pos = (int)(lowerPos - lis);
		if (*lowerPos == INT_MAX) len++;
		*lowerPos = num;

		ans[i].first = _pos;
		ans[i].second = num;
	}

	cout << len << '\n';
	
	for (int i = n - 1; i >= 0; i--) {
		if (ans[i].first == len - 1) {
			stk.push(ans[i].second);
			len--;
		}
	}

	while (stk.size()) {
		cout << stk.top() << " ";
		stk.pop();
	}



	return 0;
}
