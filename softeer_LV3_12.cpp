// https://softeer.ai/connect/devtalk/1732


#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;



vector<pair<int, int>> v;

int n, pi, ci;



int dp[200004];



int solve(int here, int popular) {

    if (here == n) return 0;



    int& ret = dp[here];

    if (ret != -1) return ret;



    // 현재 위치의 유명인을 만나지 않는 경우

    ret = solve(here + 1, popular);



    // 유명인을 만나서 인기도가 오른 경우

    if (abs(v[here].first - popular) <= abs(v[here].second)) {

        ret = max(ret, solve(here + 1, popular + 1) + 1);

    }



    return ret;

}



int main() {

    cin >> n;



    for (int i = 0; i < n; i++) {

        cin >> pi >> ci;

        v.push_back({ pi, ci });

    }



    fill(dp, dp + 200004, -1);



    cout << solve(0, 0);



    return 0;

}
