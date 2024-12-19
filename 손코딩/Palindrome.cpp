#include <bits/stdc++.h>
using namespace std;

string s;
bool Palindrom(string s) {
	int l = 0;
	int r = s.length() - 1;

	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}

	return true;
}
int main() {
	cin >> s;

	if (Palindrom(s))
		cout << "ÆÓ¸°µå·Ò";
	else
		cout << "x";

	
	return 0;
}