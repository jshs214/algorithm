#include <bits/stdc++.h>
using namespace std;

int t;
string p;
int n;

vector<int> v;

void Parse(string n) {
	string s;

	for (int i = 0; i < n.size(); i++) {
		if (n[i] >= '0' && n[i] <= '9') {
			s += n[i];
		}
		else {
			if (!s.empty()) {
				v.push_back(stoi(s));
				s.clear();  
			}
		}
	}
}

void Print() {
	cout << "[";
	for (int i = 0; i < v.size(); i++) {
		if (i != v.size() - 1)
			cout << v[i] << ",";
		else
			cout << v[i];
	}
	cout << "]" <<'\n';
}


int main() {

	cin >> t;

	while (t--) {
		v.clear();

		cin >> p;	// R, D 규칙 입력
		cin >> n;	//배열 개수

		string strN;
		cin >> strN;
		Parse(strN);


		// true 정방향, false 역방향
		bool direction = true;
		
		int startRemove = 0;
		int endRemove = 0;

		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				direction = !direction;
			}
			else if(p[i] == 'D'){
				if (direction) startRemove++;
				else endRemove++;
			}
		}

		if ((startRemove + endRemove) > n) {
			cout << "error" << '\n';
			continue;
		}
		else {
			v.erase(v.begin(), v.begin() + startRemove);
			v.erase(v.end() - endRemove, v.end());
			
			if (!direction)
				reverse(v.begin(), v.end());

			Print();
		}
		
			

	}

	return 0;
}