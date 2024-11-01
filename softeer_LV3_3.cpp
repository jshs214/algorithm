#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1000004];

int s, e, n;
vector<pair<int, int>> v;

int main(int argc, char** argv)
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({ e,s });
    }

    sort(v.begin(), v.end());

    int cnt = 0;

    cnt = 1;
    // v.first : 종료 시간, v.second : 시작 시간
    e = v[0].first;
    s = v[0].second;
    int i = 1;

    while (i < n) {
        if (e <= v[i].second) {
            s = v[i].second;
            e = v[i].first;
            cnt++;
        }

        i++;
    }

    cout << cnt;



    return 0;
}