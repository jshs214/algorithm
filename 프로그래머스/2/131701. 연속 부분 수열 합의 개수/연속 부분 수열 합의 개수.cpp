#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

set<int> _set;
int psum[2008];

int solution(vector<int> elements) {
    int answer = 0;

    // 원형 배열 처리
    int n = elements.size();
    for (int i = 0; i < n; i++) {
        elements.push_back(elements[i]);
    }

    // 부분 합 계산
    psum[0] = 0;
    for (int i = 1; i <= elements.size(); i++) {
        psum[i] = psum[i - 1] + elements[i - 1];
    }

    // 부분 수열의 합 계산
    for (int length = 1; length <= n; length++) {  // 부분 수열의 길이
        for (int start = 0; start < n; start++) {  // 시작 인덱스
            int end = start + length ;
            int tmp = psum[end] - psum[start];
            _set.insert(tmp);
        }
    }

    answer = _set.size();
    return answer;
}
