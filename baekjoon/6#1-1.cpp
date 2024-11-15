#include <bits/stdc++.h>
using namespace std;

vector<int> arr = { 1, 3, 6, 9, 10, 21, 22, 30 };

int binarySearch(int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left<=right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}


	return -1;
}
// Binary Search basic
int main() {
	
	sort(arr.begin(), arr.end());

	int target = 6;

	int ret = binarySearch(target);
	if (ret == -1) {
		cout << "Å½»ö x";
	}
	else
		cout << arr[ret];
	return 0;

}