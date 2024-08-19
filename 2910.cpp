#include <bits/stdc++.h>
using namespace std;

struct message {
	unsigned long long num;
	int idx;
	int count;
};

int n;
unsigned long long c;

map<int, message> retMap;


int main() {
	cin >> n >> c;
	
	// make hash
	unsigned long long temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;

		message m;
		m.num = temp;
		m.idx = i;
		m.count = 1;
		
		if (retMap.find(temp) != retMap.end()) {
			retMap[temp].count++;
		}
		else {
			retMap[temp] = m;
		}
	}

	vector<message> vec;

	for (int i = 0; i < retMap.size(); i++) {
		vec.push_back(retMap[i]);
	}


	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < vec.size() - i - 1; j++) {
			if (vec[j].count < vec[j + 1].count) {
				swap(vec[j], vec[j + 1]);
			}
			else if (vec[j].count == vec[j + 1].count && vec[j].idx > vec[j + 1].idx) {
				swap(vec[j], vec[j + 1]);
			}
		}
	}

	for (auto it : vec) {
		for (int i = 0; i < it.count; i++)
			cout << it.num << " ";
	}



	return 0;
}