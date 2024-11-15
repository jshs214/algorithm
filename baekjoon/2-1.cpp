#include <bits/stdc++.h>

using namespace std;

int n, m;

int dy[] = { 1,0, 0, -1 };
int dx[] = { 0,1, -1, 0 };
int arr[101][101];
int visited[101][101];
int y, x;

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            int temp = line[j] - '0';
            arr[i][j] = temp;
        }
    }

    queue<pair<int, int>>q;
    visited[0][0] = 1;
    q.push({ 0,0 });

    while (q.size()) {
        //here
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || ny >= m )    continue;
            if (arr[ny][nx] == 0 || visited[ny][nx]) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });
        }
    }
    cout << visited[n - 1][m - 1];

    //For debug
    cout << "0000000000000000000" << endl;
    for(int i = 0; i < n; i++){
         for(int j = 0; j < m; j ++){
             cout << visited[i][j] <<" ";
         }
         cout <<endl;
     }


	return 0;
}