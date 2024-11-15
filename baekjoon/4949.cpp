#include <bits/stdc++.h>
using namespace std;


bool check(string s) {
	stack<char> stk;

	for (char c : s) {
		if (c == '('|| c =='[') stk.push(c);
		else if (c == ')' || c == ']') {
			if (stk.empty()) return false;

			char top = stk.top();

			if ( (top == '(' && c == ')' ) || (top == '[' && c == ']' ) )
				stk.pop();
			else return false;
		}
		
	}

	return stk.empty();
}

int main() {
	
	string s;


	while (getline(cin, s)) {

		if (s == ".")
			break;
		
		string lineStr;
		lineStr += s;
		while (lineStr.back() != '.') {
			getline(cin, s);
			lineStr += s;
		}

		if (check(lineStr))	cout << "yes" << "\n";
		else cout << "no" << "\n";



	}


	return 0;
}