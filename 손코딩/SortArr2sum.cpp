// 두 수의 합
// 정렬된 배열에서 두 수를 찾아 합이 특정 값이 되는 
// 경우를 구하시오.

#include <bits/stdc++.h>
using namespace std;

int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int findV = 4;
vector<pair<int, int>> v;
int main() {

	int l = 0;
	int r = 10-1;

	while (l < r) {
		int sum = a[l] + a[r];
		if (sum == findV) {
			l++;
			r--;
			v.push_back({ a[l], a[r] });
		}
		else if (sum < findV)
			l++;
		else
			r--;
	}

	for (auto i : v) {
		cout << i.first << " " << i.second << '\n';
	}
	

	return 0;
}