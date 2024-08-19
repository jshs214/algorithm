#include <bits/stdc++.h>

using namespace std;

struct WV {
	int w;
	int v;
};

WV arr[100];

int n, k;

int ret= -12;


void combi(int start, vector<int> b, int kkk)
{
	if (b.size() == kkk) {
		//logic


		int weightSum =0;
		// weight check
		for (int i : b) {
			weightSum += arr[i].w;
			//cout << i << " ";
		}
		//cout << "\n";
		
		//exception
		if (weightSum> k)
			return;


		int maxValue =0;
		for (int i : b)
			maxValue+= arr[i].v;

		ret = max(ret, maxValue);
	}

	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, b, kkk);
		b.pop_back();
	}
}

int main()
{
	vector<int> b;
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		WV temp;
		cin >> temp.w >> temp.v;
		arr[i] = temp;
	}


	for (int i = 0; i < n; i++) {
		combi(-1, b, i);
	}


	cout << ret;

	return 0;
}