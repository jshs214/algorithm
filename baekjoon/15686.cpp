#include <bits/stdc++.h>
using namespace std;
int n, m;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<vector<int>> chickenCombi;

void combi(int start, vector<int> v) {
	if (v.size() == m) {
		chickenCombi.push_back(v);
		return;
	}

	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp == 1)
				house.push_back({ i,j });
			else if (temp == 2)
				chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	combi(-1, v);

	int result = 987654321;
	for (vector<int> chickenC : chickenCombi) {
		int ret = 0;
		for (pair<int, int> _house : house) {
			int _min = 987654321;
			for (int idx : chickenC) {
				int _dist = abs(_house.first - chicken[idx].first) +
					abs(_house.second- chicken[idx].second);
				_min = min(_min, _dist);
			}
			ret += _min;
		}
		result = min(ret, result);
	}

	cout << result;


	return 0;
}