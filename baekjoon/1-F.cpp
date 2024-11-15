#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		
		//´ë
		if (s[i] >= 65 && s[i] < 97) {
			if (s[i] + 13 > 90) s[i] = s[i] + 13 - 26;
			else s[i] += 13;
		}
		//¼Ò
		else if (s[i] >= 97 && s[i] < 123) {
			if (s[i] + 13 >= 123) s[i] = s[i] + 13 - 26;
			else s[i] += 13;
		}
		
	}
	
	cout << s;
}

//abcdefghijklmnopqrxtuvwxyzABCDEFGHIJKLMNOPQRXTUVWXYZ
