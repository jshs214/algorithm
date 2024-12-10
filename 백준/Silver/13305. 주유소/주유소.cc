#include <bits/stdc++.h>
using namespace std;

int n;
int _cost[100004];
int _distance[100004];

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> _distance[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> _cost[i];
	}

	
	int _prev = _cost[0];
	long long sum = _prev * _distance[0];

	for (int i = 1; i < n - 1; i++) {
		// 이전께 더 작으면
		if (_prev < _cost[i]) {
			sum += _prev * _distance[i];
		}
		// 현재가 더 작으면
		else {
			_prev = _cost[i];
			sum += _prev * _distance[i];
		}
	}

	cout << sum;

	return 0;
}