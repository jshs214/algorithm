//아래와 같이 출력되는 프로그램을 구현 하시오. 
/* ex)
Sssss
sSsss
ssSss
sssSs
ssssS
sssSs
ssSss
sSsss
Sssss
*/

#include <bits/stdc++.h>
using namespace std;

string s = "Sssss";

int main() {

	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			cout << s << "\n";
			continue;
		}

		char a = s[i -1];
		char b = s[i];
		s[i - 1] = b;
		s[i] = a;
		cout << s << "\n";
	}

	for (int i = s.size()-1; i > 0; i--) {
		char a = s[i - 1];
		char b = s[i];
		s[i - 1] = b;
		s[i] = a;
		cout << s << "\n";
	}


	return 0;
}