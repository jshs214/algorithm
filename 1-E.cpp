#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

//내가 푼거
//int alphabet[26] = { 0, };
//
//bool flag = false;
//
//int main() {
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		string str;
//		cin >> str;
//		
//		int idx = (int)str[0] - 'a';
//		alphabet[idx]++;
//	}
//
//	for (int i = 0; i < 26; i++) {
//		char c;
//		c = i + 'a';
//
//		if (alphabet[i] >= 5) {
//			flag = true;
//			cout << c;
//		}
//	}
//	if (!flag)
//		cout << "PREDAJA";
//
//
//
//	return 0;
//}

//교안
int n, cnt[26];
string s, ret;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		cnt[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) ret += i + 'a';
	}
	if (ret.size()) cout << ret;
	else cout << "PREDAJA" << endl;

}