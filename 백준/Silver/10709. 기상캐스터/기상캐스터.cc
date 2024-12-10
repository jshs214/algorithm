#include <bits/stdc++.h>
using namespace std;

int w, h;

char arr[101][101];
int ret[101][101];

char temp;

// .
int main()
{
	cin >> h >> w;
	
	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			cin >> temp;
			arr[i][j] = temp;
			ret[i][j] = -1;
		}
	}



	for (int j = 0; j < h; j++) {
		int cnt = -1;
		for (int i = 0; i < w; i++) {
			if (arr[i][j] == 'c') {
				ret[i][j] = 0;
				cnt = 0;
			}
			else if(cnt != -1){
				cnt++;
				ret[i][j] = cnt;
			}
		}
	}

	for (int j = 0; j < h; j++) {
		for (int i = 0; i < w; i++) {
			cout << ret[i][j] << " ";
		}
		cout << "\n";
	}




	return 0;
}