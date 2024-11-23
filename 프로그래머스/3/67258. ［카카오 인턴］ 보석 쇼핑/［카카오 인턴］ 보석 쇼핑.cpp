#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);

    unordered_map<string, int> m;
    set<string> set_gems(gems.begin(), gems.end());
    int gemCount = set_gems.size();

    int start = 0, end = 0;
    int minLength = gems.size() + 1; // 최소 구간 길이 초기화

    while (end < gems.size()) {
        // 보석 추가
        m[gems[end]]++;
        end++;

        // 모든 보석이 포함되었을 때
        while (m.size() == gemCount) {
            // 최소 구간 갱신
            if (end - start < minLength) {
                minLength = end - start;
                answer = {start + 1, end}; // 1-based index로 저장
            }

            // 구간 시작점 이동
            m[gems[start]]--;
            if (m[gems[start]] == 0) {
                m.erase(gems[start]);
            }
            start++;
        }
    }

    return answer;
}
