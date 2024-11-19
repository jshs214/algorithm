#include <iostream>
#include <vector>

using namespace std;

const int INF = 98765431;
int dist[104][104];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    // 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;  // 자기 자신은 0, 나머지는 INF
        }
    }

    // 승패 관계 설정
    for (vector<int> result : results) {
        int winner = result[0];
        int loser = result[1];
        dist[winner][loser] = 1;  // winner가 loser를 이김
    }

    // 플로이드-와샬: 경로 존재 여부 확인
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = 1;  // i가 j를 이길 수 있음
                }
            }
        }
    }

    // 순위 결정 가능한 선수 찾기
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] != INF || dist[j][i] != INF) {  // i와 j 간 관계가 확인됨
                count++;
            }
        }
        if (count == n) answer++;  // 모든 선수와 관계를 확인할 수 있으면 순위 결정 가능
    }

    return answer;
}
