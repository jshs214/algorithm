#include <bits/stdc++.h>
using namespace std;

//           상  하 우 좌
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int R, C, M;

struct shark {
	int y, x, speed, dir, size;
};
// shark info
vector<shark>v;

int peopleIdx = -1;

int ret = 0;

void GetShark() {
	
	for (int i = 0; i < R; i++) {
		//땅하고 가까운 상어 있으면 잡고 break;
		for (int j = 0; j < v.size(); j ++) {
			if (i == v[j].y && peopleIdx == v[j].x) {
				ret += v[j].size;
				v.erase(v.begin() + j);
				return;
			}
		}

	}

}
void ChangeDirection(int &dir) {
	if (dir == 0) dir = 1;
	else if (dir == 1) dir = 0;
	else if (dir == 2) dir = 3;
	else if (dir == 3) dir = 2;
}

void MoveShark() {
    // (y, x)에 가장 큰 상어의 정보 저장 (size, index)
    pair<int, int> a[104][104];
    memset(a, -1, sizeof(a)); // -1로 초기화

    // 모든 상어 이동
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].y;
        int x = v[i].x;
        int speed = v[i].speed;
        int dir = v[i].dir;

        // 속도 최적화
        if (dir <= 1) speed %= (2 * (R - 1));
        else speed %= (2 * (C - 1));

        // 상어 이동
        for (int j = 0; j < speed; j++) {
            y += dy[dir];
            x += dx[dir];

            // 경계 밖으로 나가면 방향 전환
            if (y < 0 || y >= R) {
                ChangeDirection(dir);
                y += dy[dir] * 2;
            }
            if (x < 0 || x >= C) {
                ChangeDirection(dir);
                x += dx[dir] * 2;
            }
        }

        // 이동 완료된 위치 저장
        v[i].y = y;
        v[i].x = x;
        v[i].dir = dir;

        // 해당 위치에 기존 상어와 비교하여 더 큰 상어만 남기기
        if (a[y][x].first == -1 || v[i].size > v[a[y][x].second].size) {
            a[y][x] = { v[i].size, i }; // 더 큰 상어 정보 저장
        }
    }

    // 중복된 상어 제거
    vector<shark> new_v;  // 살아남은 상어만 저장할 벡터
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j].first != -1) {
                new_v.push_back(v[a[i][j].second]);
            }
        }
    }
    v = new_v;  // 살아남은 상어만 원본 벡터에 반영
}



int main() {
	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		
		shark temp = { r -1, c -1, s, d-1, z };
		v.push_back(temp);
	}

	while (++peopleIdx < C) {  // 낚시꾼 이동
		GetShark();  // 상어 잡기

        // 2d array로 시간 개선
		MoveShark();  // 상어 이동
	}

	cout << ret;

	return 0;
}