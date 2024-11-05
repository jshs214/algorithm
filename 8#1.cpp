#include <bits/stdc++.h>
using namespace std;

#define max_n 6
typedef long long ll;

int n;
int tree[max_n];
int sum(int to) {

	int ret = 0;
	while (to > 0) {
		ret += tree[to];
		to -= (to & -to);
	}
	return ret;
}
void update(int idx, int value) {
	while (idx <= n) {
		tree[idx] += value;
		idx += (idx & -idx);
	}
}
int main() {
	int n = max_n;
	memset(tree, 0, sizeof(tree));
	int a[max_n] = { 0, 1, 2, 3, 4, 5 };

	for (int i = 1; i < max_n; i++) {
		update(i, a[i]);
	}

	printf("%d", sum(5) - sum(1)); //14가 나옵니다. 

	return 0;

}