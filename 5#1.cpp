#include <bits/stdc++.h>
using namespace std;

int ret, totalAmout = 12100;

vector<pair<int, int>> currency = { {10000,5},	{5000, 5}, {1000,5}, {100, 5} };

int main() {

	for (auto i : currency) {
		while (totalAmout >= i.first) {
			totalAmout -= i.first;
			i.second--;
			ret++;
		}
	}

	if (totalAmout == 0) cout << ret;
	else cout << "impossible";
		

	return 0;
}