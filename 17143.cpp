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

	// -------중복되는 상어 kill 방법 생각.
	// size, vector index
	pair<int, int> a[104][104];
	memset(a, 0, sizeof(a));

    // 상어 모두 이동
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

            if (y < 0 || y >= R) {
                ChangeDirection(dir);
                y += dy[dir] * 2; // 1칸 이동 시 overflow니 2칸 이동
            }
            if (x < 0 || x >= C) {
                ChangeDirection(dir);
                x += dx[dir] * 2; // 1칸 이동 시 overflow니 2칸 이동
            }
        }

        v[i].y = y;
        v[i].x = x;
        v[i].dir = dir;


		//중복 체크
		if (a[y][x].first == 0 && a[y][x].second == 0) {
			a[y][x].first = v[i].size;
			a[y][x].second = i;
		}
		else {
			int beforeSharkSize= a[y][x].first;
			int beforeSharkIdx = a[y][x].second;

			// 이전 상어가 더 크면
			if (beforeSharkSize > v[i].size) {
				v.erase(v.begin() + i);
				i--;
			}
			// 현재 상어가 더 크면
			else {
				a[y][x].first = v[i].size;
				a[y][x].second = i;

				v.erase(v.begin() + beforeSharkIdx);
				i--;
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

        // 2d array로 시간 개선
		MoveShark();  // 상어 이동
	}

	cout << ret;

	return 0;
}