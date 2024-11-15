#include <bits/stdc++.h>
using namespace std;

#define CW 1      // 시계 방향
#define CCW -1    // 반시계 방향

const int RIGHT = 2;
const int LEFT = 6;

int t, k;
string topni[1004];
vector<pair<int, int>> commands; // 회전 명령 저장

void rotateTopni(int num, int direction) {
    if (direction == CW) {
        rotate(topni[num].rbegin(), topni[num].rbegin() + 1, topni[num].rend());
    }
    else if (direction == CCW) {
        rotate(topni[num].begin(), topni[num].begin() + 1, topni[num].end());
    }
}

// 회전 방향을 저장
vector<int> getRotationDirections(int num, int dir) {
    vector<int> directions(t + 1, 0); // 각 톱니바퀴의 회전 방향 저장 (0: 회전 안 함)
    directions[num] = dir;

    for (int i = num; i > 1; i--) {
        if (topni[i][LEFT] != topni[i - 1][RIGHT]) {
            directions[i - 1] = -directions[i];
        }
        else {
            break;
        }
    }

    // 오른쪽 탐색
    for (int i = num; i < t; i++) {
        if (topni[i][RIGHT] != topni[i + 1][LEFT]) {
            directions[i + 1] = -directions[i];
        }
        else {
            break;
        }
    }

    return directions;
}

int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> topni[i];
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        commands.push_back({ num, dir });
    }

    for (auto i: commands) {
        int num = i.first;
        int dir = i.second;

        vector<int> directions = getRotationDirections(num, dir);

        // 회전
        for (int i = 1; i <= t; i++) {
            if (directions[i] != 0) {
                rotateTopni(i, directions[i]);
            }
        }
    }

    int ret = 0;
    for (int i = 1; i <= t; i++) {
        if (topni[i][0] == '1') {
            ret++;
        }
    }

    cout << ret << '\n';
    return 0;
}
