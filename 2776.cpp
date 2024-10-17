#include<bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
	cin >> t;

	while (t--) {
		vector<int>v;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int value;
			cin >> value;
			v.push_back(value);
		}

		sort(v.begin(), v.end());


		//¼öÃ¸ 2 logic
		cin >> m;
		for (int i = 0; i < m; i++) {
			int value;
			cin >> value;

			int left = 0, mid, ret = 0;
			int right = n-1;
			
			while (left <= right) {
				mid = (left + right) / 2;

				if (v[mid] < value) {
					left = mid + 1;
				}
				else if (v[mid] > value) {
					right = mid - 1;
				}
				else if(v[mid] == value){
					ret = 1;
					break;
				}
			}
			cout << ret << '\n';
		}

	}

	return 0;
}