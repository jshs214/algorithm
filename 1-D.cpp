#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

// 내가푼거
//char c[100];
//char temp[100];
//
//int main()
//{
//	string s;
//	
//	cin >> s;
//
//	strcpy(c, s.c_str());
//
//	for (int i = 0; i < s.length(); i++) {
//		temp[i] = c[s.length()-1 -i];
//	}
//	string strTemp = temp;
//
//	if (s == strTemp) cout << "1";
//	else cout << "0";
//
//	return 0;
//}

//교안 (답안)
int main()
{
	string s, temp;

	cin >> s;
	temp = s;
	
	reverse(s.begin(), s.end());
	if (s == temp) cout << "1";
	else cout << "0";
	return 0;
}