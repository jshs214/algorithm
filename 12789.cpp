#include <bits/stdc++.h>
using namespace std;

int n;
stack<int> st;
int a[1004];
int cnt = 1;

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		if (a[i] > cnt)
			st.push(a[i]);
		else if( cnt == a[i])
			cnt++;
		
		// stack 상시 체크
		if (st.size())
			while (st.top() == cnt){
				st.pop();
				cnt++;
				if (!st.size()) break;
			}
	}

	bool flag = true;
	// last stack 체크
	while (st.size()) {
		if (cnt == st.top()) {
			st.pop();
			cnt++;
		}
		else {
			flag = false;
			break;
		}
	}
	
	if (flag) cout << "Nice";
	else cout << "Sad";



	return 0;
}