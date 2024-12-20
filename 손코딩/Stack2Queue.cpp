//2개의 스택으로 큐 구현
#include <bits/stdc++.h>
using namespace std;

stack<int> stk1, stk2;


int solution() {
	if (stk2.empty()) {
		while (stk1.size()) {
			int tmp = stk1.top();
			stk1.pop();
			stk2.push(tmp);
		}
	}
	
	int ret = stk2.top();
	stk2.pop();
	return ret;
}
int main() {

	stk1.push(1);
	stk1.push(2);
	stk1.push(3);

	//cout << stk1.top();
	cout << solution();



	return 0;
}