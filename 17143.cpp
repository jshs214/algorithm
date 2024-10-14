#include <bits/stdc++.h>
using namespace std;

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
    // 상어 모두 이동
    for (int i = 0; i < v.size(); i++) {
        int y = v[i].y;
        int x = v[i].x;
        int speed = v[i].speed;
        int dir = v[i].dir;

        // 상어 이동
        for (int j = 0; j < speed; j++) {
            y += dy[dir];
            x += dx[dir];

            if (y < 0 || y >= R) {
                ChangeDirection(dir);
                y += dy[dir] * 2; // 경계 복귀
            }
            if (x < 0 || x >= C) {
                ChangeDirection(dir);
                x += dx[dir] * 2; // 경계 복귀
            }
        }

        // 이동한 상어 위치 업데이트
        v[i].y = y;
        v[i].x = x;
        v[i].dir = dir;
    }

    // 같은 위치에 있는 상어 처리
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].y == v[j].y && v[i].x == v[j].x) {
                // 크기가 큰 상어만 남김
                if (v[i].size > v[j].size) {
                    v.erase(v.begin() + j);
                    j--;
                }
                else {
                    v.erase(v.begin() + i);
                    i--;
                    break;
                }
            }
        }
    }
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
		MoveShark();  // 상어 이동
	}

	cout << ret;

	return 0;
}