#include <bits/stdc++.h>
using namespace std;

int lis[1004];
int cnt[1004];

int n;
int len = 0;

pair<int, int> ans[1004];
stack<int> stk;
void OlogN() {
	cin >> n;

	fill(lis, lis + 1004, INT_MAX);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		auto lowerPos = lower_bound(lis, lis + len, num);
		int _pos = (int)(lowerPos - lis);
		if (*lowerPos == INT_MAX)
			len++;

		*lowerPos = num;

		ans[i].first = _pos;
		ans[i].second = num;
	}

	cout << len;
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
}
void ON2() {
	cin >> n;
	
	int ret = 0;

	for (int i = 0; i < n; i++)
		cin >> lis[i];

	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < n; j++) {
			if (lis[j] < lis[i] && mx < cnt[j])
				mx = cnt[j];
		}

		cnt[i] = mx + 1;
		ret = max(ret, cnt[i]);
	}

	cout << ret;

}

int main() {
	//OlogN();
	ON2();
	return 0;
}