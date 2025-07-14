#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int n, p, d, ret = 0;
priority_queue< int, vector<int>, greater<int> > pq;

int main() {
	cin >> n;

	for (int i = 0; i < n; i ++)
	{
		cin >> p >> d;
		v.push_back({ d, p });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		ret += v[i].second;
		pq.push(v[i].second);

		if (pq.size() > v[i].first)
		{
			ret -= pq.top();
			pq.pop();
		}

	}
	cout << ret;



	return 0;
}