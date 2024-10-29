#include<bits/stdc++.h>
using namespace std;

const int n =18;

double scoreA, scoreB;
double dp[20][20][20];
bool isPrime[20];

void era() {
	fill(isPrime, isPrime + 20, 1);

	isPrime[0] = 0; isPrime[1] = 0;
	for (int i = 2; i < 20; i++) {
		for (int j = 2 * i; j < 20; j += i) {
			isPrime[j] = 0;
		}
	}
}

double solve(int x, int y, int count) {
	if (count == n) 
		return isPrime[x] || isPrime[y] ? 1.0 : 0.0;

	double& ret = dp[x][y][count];
	if (ret > -0.5) return ret;

	ret = 0.0;
	// µÑ´Ù ³ÖÀ» È®·ü
	ret += solve(x + 1, y + 1, count + 1) * scoreA * scoreB;
	// µÑ´Ù ¸ø³ÖÀ» È®·ü
	ret += solve(x, y, count + 1) * (1 - scoreA) * (1 - scoreB);
	// a¸¸ µæÁ¡
	ret += solve(x + 1, y, count + 1) * scoreA * (1 - scoreB);
	// b¸¸ µæÁ¡
	ret += solve(x, y + 1, count + 1) * (1 - scoreA) * scoreB;

	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	era();

	cin >> scoreA >> scoreB;
	scoreA /= 100; scoreB /= 100;

	cout << solve(0, 0, 0);

	return 0;
}