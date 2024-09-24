#include<bits/stdc++.h>
#define maxn 200005
typedef long long ll;
using namespace std;
const int INF = 987654321;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, a[44], ret = INF;
string s;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == 'T')
				a[i] |= value;
			value += 2;
		}
	}





	return 0;
}