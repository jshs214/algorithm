#include <bits/stdc++.h>
using namespace std;


int arr[1000002];
int ret[1000002];
stack<int> stk;

int n;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> arr[i];

		while (stk.size() && arr[stk.top()] < arr[i]) {
			ret[stk.top()] = arr[i];
			stk.pop();
		}
		stk.push(i);
	}
	
	while (stk.size()) {
		ret[stk.top()] = -1;

		stk.pop();
	}


	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}



	return 0;
}