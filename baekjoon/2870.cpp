#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> num;

string str;

//a : 97, z : 122

string CheckStr(string str) {
	string ret;
	
	while (true) {
		if (str.size() && str.front() == '0')str.erase(str.begin());
		else break;
	}
	if (str.size() == 0) str = "0";

	ret = str;

	return ret;
}

void ParseStr() {
	string strTemp = "";

	for (int i = 0; i < str.size(); i++) {

		if ( !( str[i] >= 97 && str[i] <= 122) ) {
			strTemp += str[i];
			
			if (i == str.size() - 1) {
				num.push_back( CheckStr(strTemp) );
			}

		}
		else {
			if (strTemp != "") {
				num.push_back(CheckStr(strTemp) );
			}
			strTemp = "";
		}
	}

}

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		ParseStr();
	}

	sort(num.begin(), num.end(), cmp);



	for (auto i : num)
		cout << i <<"\n";


	return 0;
}