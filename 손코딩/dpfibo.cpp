#include <bits/stdc++.h>
using namespace std;

int a[104];

int fibo(int n) {
	if (n <= 0)
		return 0;
	if (n == 1 || n ==2)
		return 1;

	if (a[n])
		return a[n];
	return fibo(n-1) + fibo(n - 2);

}
int main() {

	cout << fibo(6) ;

	
	return 0;
}