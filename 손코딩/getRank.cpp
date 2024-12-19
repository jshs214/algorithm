#include <bits/stdc++.h>
using namespace std;

int cnt[101];
int rank_arr[101];

void Getrank() {
	int ret = 1;

	for (int i = 100; i >= 0; i--) {
		if (cnt[i] != 0) {
			rank_arr[i] = ret;
			ret += cnt[i];
		}
	}
	
	return;
}

int main() {
	fill(cnt, cnt + 100, 0);

	// 1. 학생 수
	int n;
	cin >> n;

	// 2. 점수 반환
	vector<int> student;
	for (int i = 0; i < n; i++) {
		int score;
		cin >> score;
		cnt[score]++;
		student.push_back(score);
	}

	Getrank();

	for (int i : student) {
		cout << i << "는 " << rank_arr[i] << "등입니다.\n" ;
	}


	return 0;
}