#include<iostream>
#include <vector>

const int INF = 987654321;
int a[6][6];
bool visited[6][6];
int n;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

using namespace std;

int temp_Cnt;

void input();

int ret = -INF;

void dfs(int cnt, int value) {
    if (cnt == temp_Cnt) {
        ret = max(ret, value);
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                visited[i][j] = 1;

                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                    if (!visited[ny][nx]) {
                        visited[ny][nx] = 1;

                        int next_value = value + a[i][j] + a[ny][nx];
                        dfs(cnt + 1, next_value);

                        visited[ny][nx] = 0;
                    }
                }

                visited[i][j] = 0;
            }
        }
    }
}
int main(int argc, char** argv)
{
    input();

    if (n == 2) {
        temp_Cnt = 2;
    }
    else {
        temp_Cnt = 4;
    }

    dfs(0, 0);
    cout << ret;


    return 0;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

}