#include <bits/stdc++.h>
using namespace std;

bool che[4000004];
int n;
int ret = 0;

vector<int> era(int n) {
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i <= n; i++)
		if (che[i] == 0) 
			v.push_back(i);

	return v;
}
int main() {
	cin >> n;

	vector<int> v;
	v = era(n);

	
	int low =0, high =0;

	while (high >= low && high < v.size()) {
		int sum = 0;

		for (int i = low; i <= high; i++) {
			sum += v[i];
		}
		if (n >= sum)	high++;
		else if (n < sum) low++;

		if (n == sum) ret++;
	}

	cout << ret;


	return 0;
}