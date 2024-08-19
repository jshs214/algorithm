#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ≥ª «Æ¿Ã
#if 0
int n = 9;
int r = 7;

bool flag = false;
vector<int> arr;

void MakePermutation(int depth) {
	if (r == depth && flag == false) {
		int sum = 0;
		for (int i = 0; i < r; i++) {
			sum += arr[i];
		}
		if (sum == 100) {
			for (int i = 0; i < r; i++) {
				cout << arr[i] << endl;
			}
			flag = true;
		}
			
		return;
	}
	for (int i = depth; i < n; i++) {
		swap(arr[i], arr[depth]);
		MakePermutation(depth + 1);
		swap(arr[i], arr[depth]);
	}

}

int main() {
	
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	MakePermutation(0);

	return 0;
}
#else
#endif
int main() {
	int n = 9;
	int r = 7;

	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());

	do {
		int sum = 0;
		for (int i = 0; i < r; i++)
			sum += arr[i];
		if (sum == 100)
			break;

	} while (next_permutation(arr.begin(), arr.end()));

	for (int i = 0; i < r; i++)
		cout << arr[i] <<endl;

	return 0;
}

