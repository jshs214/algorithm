#include <bits/stdc++.h>
using namespace std;

int a[10] = { 1,4,7,8,9,10,12,13,14, 20 };

int main() {
	int l = 0;
	int r = 10 - 1;

	int findN = 13;

	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == findN) {
			cout << mid +1 << "¹øÂ°";
			break;
		}
		else if (a[mid] > findN) {
			r = mid - 1;
		}
		else
			l = mid + 1;
	}


	return 0;
}