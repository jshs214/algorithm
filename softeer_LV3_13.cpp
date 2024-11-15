#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define n 4

#define WIN 0
#define LOSE 1
#define BIGI 2

double F[5];
double prob[5][5][3];
double ret;

vector<int> score(5, 0);
// 경기 경우의 수
pair<int, int> arr[6] = {
    {1,2}, {1,3}, {1,4}, {2, 3}, {2,4}, {3,4}
};

void solve(int here, double tot, vector<int> score) {
    if (here == 6) {
        //vector<int> tmp = score;
        //sort(tmp.begin(), tmp.end());

        //if (score[1] >= tmp[3])
        //    ret += tot;
        return;
    }

    int a = arr[here].first;
    int b = arr[here].second;

    for (int i = 0; i < 3; i++) {
        double p = prob[a][b][i];
        vector<int> tmp;

        if (i == WIN) tmp[a] += 3;
        else if (i == LOSE) tmp[b] += 3;
        else if (i == BIGI) {
            tmp[a]++; tmp[b]++;
        }

        solve(here + 1, tot * p, tmp);
    }

}

int main() {
    for (int i = 1; i <= n; i++)
        cin >> F[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            prob[i][j][WIN] = (4 * F[i]) / (5 * F[i] + 5 * F[j]);
            prob[i][j][LOSE] = (4 * F[j]) / (5 * F[i] + 5 * F[j]);
            prob[i][j][BIGI] = (F[i] + F[j]) / (5 * F[i] + 5 * F[j]);
        }
    }

    //solve(0, 1.0, score);
    cout << ret;

    return 0;
}