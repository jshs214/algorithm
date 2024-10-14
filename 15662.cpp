#include <bits/stdc++.h>
using namespace std;

#define CW 1  // 시계 방향
#define CCW -1 // 반시계 방향

const int RIGHT = 2;
const int LEFT = 6;

int t, k;
string topni[1004];   // 톱니바퀴 상태 저장
vector<pair<int, int>> commands; // 회전 명령 저장

// 톱니바퀴 회전 함수
void rotateTopni(int num, int direction) {
    if (direction == CW) {
        rotate(topni[num].rbegin(), topni[num].rbegin() + 1, topni[num].rend());
    }
    else if (direction == CCW) {
        rotate(topni[num].begin(), topni[num].begin() + 1, topni[num].end());
    }
}

// 회전 방향을 미리 결정하는 함수
vector<int> getRotationDirections(int num, int dir) {
    vector<int> directions(t + 1, 0); // 각 톱니바퀴의 회전 방향 저장 (0: 회전 안 함)
    directions[num] = dir; // 초기 회전 설정

    // 왼쪽 탐색
    for (int i = num; i > 1; i--) {
        if (topni[i][LEFT] != topni[i - 1][RIGHT]) {
            directions[i - 1] = -directions[i]; // 반대 방향으로 회전
        }
        else {
            break; // 회전하지 않으면 중단
        }
    }

    // 오른쪽 탐색
    for (int i = num; i < t; i++) {
        if (topni[i][RIGHT] != topni[i + 1][LEFT]) {
            directions[i + 1] = -directions[i]; // 반대 방향으로 회전
        }
        else {
            break; // 회전하지 않으면 중단
        }
    }

    return directions;
}

int main() {
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cin >> topni[i]; // 톱니바퀴 상태 입력
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        commands.push_back({ num, dir });
    }

    // 명령 실행
    for (auto& cmd : commands) {
        int num = cmd.first;
        int dir = cmd.second;

        // 각 톱니바퀴의 회전 방향 결정
        vector<int> directions = getRotationDirections(num, dir);

        // 회전 적용
        for (int i = 1; i <= t; i++) {
            if (directions[i] != 0) {
                rotateTopni(i, directions[i]);
            }
        }
    }

    // 최종 상태에서 12시 방향이 S극(1)인 톱니바퀴 개수 계산
    int ret = 0;
    for (int i = 1; i <= t; i++) {
        if (topni[i][0] == '1') {
            ret++;
        }
    }

    cout << ret << '\n';
    return 0;
}
