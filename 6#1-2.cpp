#include <bits/stdc++.h>
using namespace std;

int t, n, m;

vector<int> v1;

bool BinarySearch(int target) {
	int left = 0;
	int right = v1.size()-1;
	int mid;
	while (left <= right) {
		mid = (right + left) / 2;

		if (v1[mid] > target) {
			right = mid - 1;
		}
		else if (v1[mid] < target) {
			left = mid + 1;
		}
		else return true;
	}

	return false;
}

int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		
		// v1.
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			v1.push_back(temp);
		}
		sort(v1.begin(), v1.end());

		cin >> m;
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;

			if (BinarySearch(temp) ) {
				cout << "큰돌이는 기억해!" << '\n';
			}
			else
				cout << "큰돌이는 까먹었어!" << '\n';
		}

	}
	return 0;
}