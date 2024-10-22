#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> v1, v2;
vector<long long> sumV1, sumV2;

// 부분합을 구하는 함수
void calcSubsetSums(const vector<int>& arr, vector<long long>& sums) {
    int size = arr.size();
    for (int i = 0; i < (1 << size); i++) {  // 2^size 만큼 모든 부분집합 탐색
        long long sum = 0;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {  // i의 j번째 비트가 1이면 해당 원소 포함
                sum += arr[j];
            }
        }
        sums.push_back(sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> c;

    // 입력을 절반으로 나눔
    int mid = n / 2;
    v1.resize(mid);
    v2.resize(n - mid);

    for (int i = 0; i < mid; i++) cin >> v1[i];
    for (int i = 0; i < n - mid; i++) cin >> v2[i];

    // 각 배열의 부분합을 구함
    calcSubsetSums(v1, sumV1);
    calcSubsetSums(v2, sumV2);

    // sumV2를 정렬 (이진 탐색을 위해)
    sort(sumV2.begin(), sumV2.end());

    long long cnt = 0;
    // sumV1의 각 부분합에 대해 sumV2에서 조건을 만족하는 경우의 수를 찾음
    for (long long s1 : sumV1) {
        cnt += upper_bound(sumV2.begin(), sumV2.end(), c - s1) - sumV2.begin();
    }

    cout << cnt << "\n";
    return 0;
}
