//dfs

#include<iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int s, t, n, m;

vector<int> adj[200006];
vector<int> Radj[200006];

int startVisited[100005];
int endVisited[100005];
int RstartVisited[100005];
int RendVisited[100005];

void dfs(int here, int cnt, vector<int> adj, int visited[]) {
    visited[here] = cnt;

    for (int there : adj[here]) {
        if (visited[there]) continue;

        dfs(there, cnt + 1, adj, visited);
    }

    return;
}


int main(int argc, char** argv)
{
    memset(startVisited, 0, sizeof(startVisited));
    memset(endVisited, 0, sizeof(endVisited));
    memset(RstartVisited, 0, sizeof(RstartVisited));
    memset(RendVisited, 0, sizeof(RendVisited));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cin >> s >> t;

    //Ãâ±Ù
    dfs(s, 1, adj, startVisited);
    //Åğ±Ù
    dfs(t, 1, adj, endVisited);
    //Ãâ±Ù
    dfs(s, 1, Radj, RstartVisited);
    //Åğ±Ù
    dfs(t, 1, Radj, RendVisited);




    int cnt = 0;
    for (int i = 0; i < 100005; i++) {
        if (startVisited[i] && endVisited[i] && RstartVisited[i] && RendVisited[i])
            cnt++;
    }

    // s, t µÎ °³
    if (cnt < 2)
        cout << 0;
    else
        cout << cnt - 2;


    return 0;
}