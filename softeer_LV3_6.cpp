#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
int l, r, mid;

vector<int> v;

int solve(int num) {
    l = 0;
    r = n - 1;

    int leftCnt = -987654321;
    int rightCnt = -987654321;

    while (l <= r) {
        mid = (l + r) / 2;

        if (num > v[mid]) {
            l = mid + 1;
        }
        else if (num < v[mid]) {
            r = mid - 1;
        }
        else {
            //(num == v[mid])
            leftCnt = mid - 0;
            rightCnt = n - 1 - mid;
            break;
        }
    }

    if (leftCnt + rightCnt < 0)
        return 0;
    else
        return leftCnt * rightCnt;
}


int main(int argc, char** argv)
{
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    while (q--) {
        int num;
        cin >> num;
        cout << solve(num) << '\n';
    }

    return 0;
}