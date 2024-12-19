#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
	cin >> s;

	int left = 0;
	int right = s.length() - 1;
	
	while (left < right) {
		char c = s[left];
		s[left] = s[right];
		s[right] = c;

		left++; right--;
	}

	cout << s;

	
	return 0;
}