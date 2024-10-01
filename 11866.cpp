#include <bits/stdc++.h>
using namespace std;

vector<int> ret;
deque<int> q;

int n, k;


int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		q.push_back(i);
	
	while (q.size()) {

		for (int i = 0; i < k - 1; i++) {
			int n = q.front();
			q.pop_front();
			q.push_back(n);
		}
		
		int sunyeol = q.front(); q.pop_front();
		ret.push_back(sunyeol);


		
	}

	cout << "<";
	for (int i = 0; i < ret.size(); i ++) {
		if (i != ret.size() - 1)
			cout << ret[i] << ", ";
		else cout << ret[i];
	}
	cout << ">";

	return 0;
}