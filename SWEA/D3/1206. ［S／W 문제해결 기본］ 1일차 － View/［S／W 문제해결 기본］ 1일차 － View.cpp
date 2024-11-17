#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    for (int test_case = 1; test_case <= 10; ++test_case) {
        int n;
        cin >> n;

        vector<int> buildings(n);
        for (int i = 0; i < n; i++)
            cin >> buildings[i];

        int totalView = 0;

        for (int i = 2; i < n - 2; i++) {
            int cur = buildings[i];
            
            // 좌측 2칸과 우측 2칸 중 가장 높은 건물 찾기
            int leftMax = max(buildings[i - 1], buildings[i - 2]);
            int rightMax = max(buildings[i + 1], buildings[i + 2]);
            int maxNeighbor = max(leftMax, rightMax);

            // 현재 건물이 양쪽 모두보다 높은 경우
            if (cur > maxNeighbor) {
                totalView += (cur - maxNeighbor);
            }
        }

        cout << "#" << test_case << " " << totalView << "\n";
    }

    return 0;
}
