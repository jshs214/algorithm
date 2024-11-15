#include <iostream>
using namespace std;

int a[100004];
int leftDP[100004], rightDP[100004];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 연속된 구간의 최댓값 계산
    leftDP[0] = a[0];
    for (int i = 1; i < n; i++) {
        leftDP[i] = max(leftDP[i - 1] + a[i], a[i]);
    }
    rightDP[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightDP[i] = max(rightDP[i + 1] + a[i], a[i]);
    }

    // 구간 별 max값 갱신
    int maxValue = leftDP[0];
    for (int i = 1; i < n; i++) {
        maxValue = max(maxValue, leftDP[i]);
        leftDP[i] = maxValue;
    }
    maxValue = rightDP[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxValue = max(maxValue, rightDP[i]);
        rightDP[i] = maxValue;
    }
    //////////////////////////////////////////////

    int ret = -987654321;
    for (int i = 1; i < n - 1; i++) {
        ret = max(leftDP[i - 1] + rightDP[i + 1], ret);
    }
    cout << ret;


    return 0;
}