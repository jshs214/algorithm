#include <bits/stdc++.h>
using namespace std;


int alphabet[26] = { 0 , };

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string name;
	cin >> name;

	int holsu = 0;
	char center = '-';

	
	for (int i = 0; i < name.length(); i++) {
		int ascii = (int)name[i];
		
		alphabet[ascii - 'A']++;	
	}
	
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == 0) continue;
		
		if (alphabet[i] % 2 == 1) {
			holsu++;
			center = i + 'A';
		}
	}

	if (holsu > 1 || holsu == 1 && name.length() % 2 == 0) {
		cout << "I'm Sorry Hansoo" << "\n";
	}
	else {
		string before, post;

		for (int i = 0; i < 26; i++) {
			string s(alphabet[i] / 2, i + 'A');
			before += s;
			post = s + post;
		}
		if (name.length() % 2 == 1) {
			before += center;
		}

		cout << before << post << "\n";
	}

	

}