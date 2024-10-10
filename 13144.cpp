#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[100004];
ll visited[100004];

int ret = 0;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int low = 0; int high = 0;
	
	while (high < n) {
		if (!visited[a[high]]) {
			visited[a[high]]++;
			high++;
		}
		else {
			ret += high - low;
			visited[a[low]]--;
			low++;
		}	
	}

	
	ret += ((high-low) * (high - low + 1)) / 2;
	
	cout << ret;


	return 0;
}