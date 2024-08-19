#include <bits/stdc++.h>
using namespace std;


//retry ù±

int n, temp;
int treemap[65][65];

string compress(int row, int col, int size) {
    int sum = 0;
    int totalPixels = size * size;

    for (int i = row; i < row + size; ++i) {
        for (int j = col; j < col + size; ++j) {
            sum += treemap[i][j];
        }
    }

    if (sum == totalPixels) return "1";
    if (sum == 0) return "0";

    int halfSize = size / 2;
    string topLeft = compress(row, col, halfSize);
    string topRight = compress(row, col + halfSize, halfSize);
    string bottomLeft = compress(row + halfSize, col, halfSize);
    string bottomRight = compress(row + halfSize, col + halfSize, halfSize);

    return "(" + topLeft + topRight + bottomLeft + bottomRight + ")";
}


int main() {
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			treemap[i][j] = s[j] -'0';
		}
	}

    cout << compress(0, 0, n);



}