#include <bits/stdc++.h>
using namespace std;

int a[14];
int b[102];
int minValue = INT_MAX, maxValue = -INT_MAX;	

int n = 5;
int k = 3;

int _plus, _minus, _mul, _div;

void makePermutation(int depth) {
	if (n-1 == depth) {
		// logic
		int ret=0;
		if (b[0] == 1) {
			ret = a[0] + a[1];
		}
		else if (b[0] == 2) {
			ret = a[0] - a[1];
		}
		else if (b[0] == 3) {
			ret = a[0] * a[1];
		}
		else if (b[0] == 4) {
			ret = a[0] / a[1];
		}

		for (int i = 1; i < n - 1; i++) {
			if (b[i] == 1) {
				ret += a[i + 1];
			}
			else if (b[i] == 2) {
				ret -= a[i + 1];
			}
			else if (b[i] == 3) {
				ret *= a[i + 1];
			}
			else if (b[i] == 4) {
				ret /= a[i + 1];
			}
		}
		minValue = min(ret, minValue);
		maxValue = max(ret, maxValue);
		
		return;
	}

	for (int i = depth; i < n-1; i++) {
		swap(b[i], b[depth]);
		makePermutation(depth + 1);
		swap(b[i], b[depth]);
	}
}


int main() {
	// input 1
	cin >> n;
	// input 2
	for (int i = 0; i < n; i++)
		cin >> a[i];

	// input 3
	// '+', '-', 'x', '/' 
	int idx =0;
	cin >> _plus;
	for (int i = 0; i < _plus; i++)
		b[i] = 1;
	cin >> _minus;	idx += _plus;
	for (int i = 0; i < _minus; i++)
		b[i + idx] = 2;
	cin >> _mul;	idx += _minus;
	for (int i = 0; i < _mul; i++)
		b[i + idx] = 3;
	cin >> _div;	idx += _mul;
	for (int i = 0; i < _div; i++)
		b[i + idx] = 4;
	
	// permutation
	makePermutation(0);

	cout << maxValue << '\n' << minValue;

	return 0;
}

