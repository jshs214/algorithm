#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;

int ret = INT_MAX;
int a, b;
int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	ret = v[0].first;
	ret += v[0].second;

	for (int i = 1; i < v.size(); i++)
	{
		if (ret > v[i].first)
		{
			ret += v[i].second;
		}
		else {
			ret = v[i].first;
			ret += v[i].second;
		}

	}

	cout << ret;

	return 0;
}