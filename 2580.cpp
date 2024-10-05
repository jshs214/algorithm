#include <bits/stdc++.h>
using namespace std;

const int N = 9;

int a[N][N];
bool isSolve = false;

vector<pair<int, int>> coord;

bool rowCheck(int y) {
    bool visited[10] = { 0, };

    for (int i = 0; i < N; i++) {
        int num = a[y][i];
        if (num != 0) {
            if (visited[num]) return false;
            visited[num] = true;
        }
    }

    return true;
}

bool colCheck(int x) {
    bool visited[10] = { 0, };
    for (int i = 0; i < N; i++) {
        int num = a[i][x];
        if (num != 0) {
            if (visited[num]) return false;
            visited[num] = true;
        }
    }

    return true;
}

bool rectCheck(int y, int x) {
    bool visited[10] = { 0, };
    int startRow = (y / 3) * 3;
    int startCol = (x / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = a[startRow + i][startCol + j];
            if (num != 0) {
                if (visited[num]) return false;
                visited[num] = true;
            }
        }
    }

    return true;
}

bool isValid(int y, int x, int num) {
    a[y][x] = num;
    bool valid = rowCheck(y) && colCheck(x) && rectCheck(y, x);
    a[y][x] = 0;
    return valid;
}

void solve(int depth) {

    if (depth == coord.size()) {
        isSolve = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return;
    }

    // ºóÄ­ °³¼ö Å½»ö
    int ny = coord[depth].first;
    int nx = coord[depth].second;

    for (int num = 1; num <= 9; num++) {
        if (isValid(ny, nx, num)) {
            a[ny][nx] = num;  

            if (isSolve) return;
            solve(depth + 1);

            
            a[ny][nx] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0)
                coord.push_back({ i,j });
        }
    }

    solve(0);

    return 0;
}
