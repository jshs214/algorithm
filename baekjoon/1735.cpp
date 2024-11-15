#include <bits/stdc++.h>
using namespace std;

struct su {
	int parents;
	int mom;
};
su a, b;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
void sumSolve() {
	su sum;
	
	int aParents = a.parents * b.mom;
	int bParents = b.parents * a.mom;

	sum.parents = aParents + bParents;
	sum.mom = a.mom * b.mom;

	
	int _gcd =  gcd(sum.parents, sum.mom);
	cout << sum.parents / _gcd << " " << sum.mom / _gcd;
}

int main() {
	cin >> a.parents >> a.mom;
	cin >> b.parents >> b.mom;

	sumSolve();


	return 0;
}