#include <bits/stdc++.h>

using namespace std;

int prefix_sum[26][200000] = { 0 };

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	string s;
	cin >> s;

	for (int i = 0; i < (int)s.size(); ++i) {
		if (i != 0) {
			for (int j = 0; j < 26; ++j)
				prefix_sum[j][i] = prefix_sum[j][i - 1];
		}

		++prefix_sum[s[i] - 'a'][i];
	}

	int q;
	cin >> q;

	while (q-- > 0) {
		char ch;
		int left, right;
		cin >> ch >> left >> right;

		if (left == 0)
			cout << prefix_sum[ch - 'a'][right] << '\n';
		else
			cout << prefix_sum[ch - 'a'][right] - prefix_sum[ch - 'a'][left - 1] << '\n';
	}
}

