#include <bits/stdc++.h>
using namespace std;

bool che[101];

void isPrime(int n) {
	for (int i = 2; i <= n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i) {
			che[j] = 1;
		}
	}
}
bool check(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n % 2 == 0) return 0;
	for (int i = 3; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int main() {
	
	isPrime(100);
	for (int i = 1; i < 100; i++) {
		if (!che[i])
			cout << i << "는 소수입니다\n";
		else
			cout << i << "는 소수아닙니다\n";
	}

	return 0;
}