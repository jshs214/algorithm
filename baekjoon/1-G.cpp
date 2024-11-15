#include<bits/stdc++.h>

using namespace std;

int n;
string p;

int main() {
	
	cin >> n;
	//패턴
	cin >> p;

	long long pos = p.find("*");

	string start = p.substr(0, pos);
	string end = p.substr(pos+1);
	
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		// 비교 자체가 안되는 반례
		if (str.size() <  start.size() + end.size()) cout << "NE" << endl;
		else {
			if (str.substr(0, start.size()) == start && str.substr(str.size() - end.size()) == end) cout << "DA" << endl;
			else cout << "NE" << endl;
		}
	}


}