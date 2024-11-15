#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int max_n = 5005;

vector<pair<int, char>> adj[max_n];

int n, m;
string sLikeFather;
int ret = -987654321;

int LCS(const string& str1, const string& str2) {
    int len1 = str1.size(), len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}


void dfs(int here, string str) {
    if (adj[here].empty() && !str.empty()) {
        int lcs_length = LCS(str, sLikeFather);
        ret = max(ret, lcs_length);

        cout << "경로: " << str << " | LCS 길이: " << lcs_length << '\n';
    }


    for (auto vv : adj[here]) {
        dfs(vv.first, str + vv.second); 
    }
}

int main() {
    cin >> n >> m;
    cin >> sLikeFather;


    for (int i = 0; i < m; i++) {
        int ss, ee;
        char _c;
        cin >> ss >> ee >> _c;
        adj[ss].push_back({ ee, _c });
    }

 
    for (int i = 1; i <= n; i++) { 
        string str = "";
        dfs(i, str);
    }

    cout << "최댓값 LCS 길이: " << ret << endl;

    return 0;
}
