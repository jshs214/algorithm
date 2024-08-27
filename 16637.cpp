#include <bits/stdc++.h>
using namespace std;

int ret = -987654321;
int n;
string s;
vector<int> num;
vector<char> op;

int calculate(int a, int b, char c) {
	if (c == '+') return a + b;
	if (c == '-') return a - b;
	if (c == '*') return a * b;

}

void go(int here, int _num) {
	if (here == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}
	
	go(here + 1, calculate(_num, num[here + 1], op[here]));
	if (here + 2 <= num.size() - 1) {
		int temp = calculate(num[here + 1], num[here + 2], op[here + 1]);
		go(here + 2, calculate(_num, temp, op[here]));
	}
	return;

}

int main() {
	cin >> n;

	cin >> s;
	for (int i = 0; i < n; i++) {
		if (i % 2 != 0) {
			op.push_back(s[i]);
		}
		else {
			num.push_back(s[i] -'0');
		}
		
	}
	go(0, num[0]);
	cout << ret;

	return 0;
}