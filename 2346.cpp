#include<bits/stdc++.h>
using namespace std;

int n;
deque<pair<int,int> > dq;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		dq.push_back({ temp, i+1 });
	}

	while (!dq.empty()) {
		int cnt = dq.front().first;
		cout << dq.front().second << " ";
		dq.pop_front();

		if (dq.empty()) break;

		if (cnt > 0) {
			for (int i = 0; i < cnt - 1; i++) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else{
			for (int i = cnt; i < 0; i++) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}


	return 0;
}