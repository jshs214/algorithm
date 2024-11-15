#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
stack<pair<ll, ll>> st;

ll now, ret =0;

// step 1: 중복 없는 case
void no_duplicate();

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> now;
		
		long long cnt = 1;
		while (!st.empty() && st.top().first <= now) {
			ret += st.top().second;

			if (st.top().first == now)
				cnt = st.top().second + 1;
			else
				cnt = 1;

			st.pop();
		}
		if (st.size()) ret++;

		st.push({ now, cnt });
	}

	cout << ret;


	return 0;
}

void no_duplicate() {
	cin >> n;
	
	stack<ll> s;

	ll ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> now;

		while (!s.empty() && s.top() < now) {
			s.pop();
			ret++;
		}
		
		if (s.size()) ret++;
		s.push(now);
		
	}

	cout << ret;
}