#include<iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, m;
char a[1004][1004];

int visited[1004][1004];
int ghostVisited[1004][1004];

int startY, startX;
int destinationY, destinationX;

vector<pair<int, int>> ghost;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void inputSetting() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'D') {
                destinationY = i; destinationX = j;
            }
            else if (a[i][j] == 'G') {
                ghost.push_back({ i,j });
            }
            else if (a[i][j] == 'N') {
                startY = i; startX = j;
            }

        }
    }
}
void MovePeople() {
    queue<pair<int, int>> q;
    q.push({ startY, startX });
    visited[startY][startX] = 1;

    while (q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx]) continue;
            if (a[ny][nx] == '#') continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }
}
void MoveGhost() {
    queue<pair<int, int>> q;
    memset(ghostVisited, 98765432, sizeof(ghostVisited));

    for (auto& g : ghost) {
        q.push(g);
        ghostVisited[g.first][g.second] = 1;
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

            //유령이 가려고 하는 곳이 현재보다 작으면 컨티뉴
            if (ghostVisited[ny][nx] <= ghostVisited[y][x] + 1) continue;

            ghostVisited[ny][nx] = ghostVisited[y][x] + 1;
            q.push({ ny, nx });
        }
    }
}


int main(int argc, char** argv)
{
    inputSetting();
    MoveGhost();
    MovePeople();

    int peopleRet = visited[destinationY][destinationX];
    int ghostRet = ghostVisited[destinationY][destinationX];

    //반례
    if (peopleRet == 0) {
        cout << "No";
        return 0;
    }

    if (peopleRet <= ghostRet) cout << "Yes";
    else cout << "No";



    return 0;
}