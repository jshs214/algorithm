#include <bits/stdc++.h>
using namespace std;

deque<int> q;
int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		q.push_back(i);


	while (q.size() > 1) {
		q.pop_front();

		int temp = q.front();
		q.pop_front();
		
		q.push_back(temp);
	}

	
	cout << q.front();

	return 0;
}