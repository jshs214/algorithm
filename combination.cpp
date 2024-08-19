#include <bits/stdc++.h>

using namespace std;

vector<int> combination;

int k = 3;
int n = 5;

void combi(int start, vector<int> b){
	if (b.size() == k) {
		//print
		for (int i : b)
			cout << i << " ";
		cout << "\n";
		return;
	}
	
	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}

}

int main()
{

	vector<int> b;
	combi(-1, b);

	return 0;
}