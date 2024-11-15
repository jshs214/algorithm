#include <bits/stdc++.h>

using namespace std;

int c, b, a;	//주차 요금 c < b < a
int n[102];

void solve()
{
	int sum = 0;

	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		for (int j = start; j < end; j++) {
			n[j]++;
		}
	}

	for (int i = 0; i < 102; i++) {
		if (n[i] == 1)
			sum += n[i] * a;
		if (n[i] == 2)
			sum += n[i] * b;
		if (n[i] == 3)
			sum += n[i] * c;

	}

	cout << sum;
	

}
int main() {
	cin >> a >> b >> c;

	solve();
	
	return 0;
}