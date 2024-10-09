#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue <double> pq;
double score;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> score;
		if (pq.size() == 5) {
			pq.push(score);
			pq.pop();
		}
		else pq.push(score);
	}

	vector<double> ret;

	while (pq.size()) {
		ret.push_back(pq.top());
		pq.pop();
	}
	
	reverse(ret.begin(), ret.end());

	for (auto i : ret) cout << i << '\n';

	return 0;
}