#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n;
string s;

vector<char> op;
vector <int> num;

int ret = -INF;

int oper(char a, int b, int c) {
	if (a == '+') return b + c;
	else if (a == '*') return b * c;
	else if (a == '-') return b -c;
}

void go(int here, int _num){
	if (here == num.size() - 1) {
		ret = max(ret, _num);
		return;
	}

	go(here + 1, oper(op[here], _num, num[here + 1]));

	if (here + 2 <= num.size() - 1) {
		int temp = oper(op[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(op[here], _num, temp) );
	}

}


int main() {
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 1)
			op.push_back(s[i]);
		else num.push_back((int)s[i] - '0');
	}
	go(0, num[0]);

	cout << ret;


	return 0;
}