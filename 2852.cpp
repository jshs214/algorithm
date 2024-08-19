#include <bits/stdc++.h>
using namespace std;

int n;
string str;


int total1;
int total2;
int team;
int score1;
int score2;
int prevTime;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> team >> str;
		
		int minute = stoi(str.substr(0, 2)) * 60;
		int second = stoi(str.substr(3, 2));

		if (score1 > score2) {
			total1 = total1 + minute + second - prevTime;
		}
		else if (score1 < score2) {
			total2 = total2 + minute + second - prevTime;
		}
		
		if (team == 1) score1++;
		else score2++;

		prevTime = minute  + second;

	}

	if (score1 > score2) total1 = total1 + 60 * 48 - prevTime;
	else if (score1 < score2) total2 = total2 + 60 * 48 - prevTime;

	printf("%02d:%02d\n", total1 / 60, total1 % 60);
	printf("%02d:%02d\n", total2 / 60, total2 % 60);



	


	return 0;
}