#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tc = 3, n;

vector<int> a[4];
vector<int> sortA[4];

int solve(int i, int num) {
    auto upper_pos = upper_bound(sortA[i].begin(), sortA[i].end(), num);
    int _pos = (int)(upper_pos - sortA[i].begin());

    return n - _pos + 1;
}

int main(int argc, char** argv)
{
    cin >> n;

    // 1 ~ 3 case
    for (int j = 0; j < tc; j++) {
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a[j].push_back(temp);
        }
        sortA[j] = a[j];
    }
    sort(sortA[0].begin(), sortA[0].end());
    sort(sortA[1].begin(), sortA[1].end());
    sort(sortA[2].begin(), sortA[2].end());

    // 1~3 гу case
    for (int i = 0; i < n; i++) {
        int value = 0;
        for (int j = 0; j < tc; j++) {
            value += a[j][i];
        }
        a[3].push_back(value);
    }
    sortA[3] = a[3];
    sort(sortA[3].begin(), sortA[3].end());

    // 1~3
    for (int i = 0; i < tc; i++) {
        for (int j = 0; j < n; j++) {
            cout << solve(i, a[i][j]) << " ";
        }
        cout << '\n';
    }

    // 1~3 гу case

    for (int j = 0; j < n; j++) {
        cout << solve(3, a[3][j]) << " ";
    }


    return 0;
}