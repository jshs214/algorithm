#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int a[100005];
int think[100005];

int n, m;
int ret = 0;

int main() {
    memset(think, -1, sizeof(think)); // -1로 초기화하여 방문 여부 확인

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int idx1, idx2;
        cin >> idx1 >> idx2;

        if (a[idx1] > a[idx2]) {
            if (think[idx1] != 0)
                think[idx1] = 1;
            think[idx2] = 0;
        }
        else if (a[idx1] < a[idx2]) {
            if (think[idx2] != 0)
                think[idx2] = 1;
            think[idx1] = 0;
        }
        else {
            think[idx1] = 0;
            think[idx2] = 0;
        }

    }


    for (int i = 1; i <= n; i++) {
        if (think[i] == 1 || think[i] == -1)
            ret++;
    }
    cout << ret;

    return 0;
}
