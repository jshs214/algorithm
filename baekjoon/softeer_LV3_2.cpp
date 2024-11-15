#include<iostream>

using namespace std;
int a[1000005];
int n, k;
int s, e;
float avg;

int main(int argc, char** argv)
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    while (k--) {
        cin >> s >> e;
        double sum = a[e] - a[s - 1];
        int num = (e + 1 - s);

        avg = sum / num;
        printf("%.2f\n", avg);

    }


    return 0;
}