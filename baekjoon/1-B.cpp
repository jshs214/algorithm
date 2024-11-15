#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

#if 0
int main() 
{
	string s;
	char cArr[100];
	
	cin >> s;
	
	int outArr[26] = { 0, };
	
	strcpy(cArr, s.c_str());

	for (int i = 0; i < 100; i++) {
		int num = (int)cArr[i] -97;
		if (num < 0 || num > 26) break;

		outArr[num]++;
	}

	for (int i = 0; i < 26; i++)
		cout << outArr[i] << " ";

	return 0;
}
#endif
int main()
{
	int outArr[26] = { 0, };
	string str;
	cin >> str;

	for (char a : str) {
		outArr[a - 'a']++;
	}
	for (int i = 0; i < 26; i++)
		cout << outArr[i] << " ";
}