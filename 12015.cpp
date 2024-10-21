#include <bits/stdc++.h>

using namespace std;

int lis[1000005];
int n, len = 0;

pair<int, int> ans[1000005];
stack<int> stk;

int main() {
	cin >> n;

	fill(lis, lis + 1000005, -1);
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		auto lowerPos = lower_bound(lis, lis + len, num);
		int _pos = (int)(lowerPos - lis);
		//if (*lowerPos == -1) len++;
		*lowerPos = num;

		//ans[i].first = _pos;
		//ans[i].second = num;
	}

	cout << len <<"\n";

	//for (int i = n - 1; i >= 0; i--) {
	//	if (ans[i].first == len - 1) {
	//		stk.push(ans[i].second);
	//		len--;
	//	}
	//}

	//while (stk.size()) {
	//	cout << stk.top() << " ";
	//	stk.pop();
	//}
	

	return 0;
}