#include<iostream>
#include <vector>

using namespace std;

int n, k;
string s;

int ret = 0;
vector<int> robot;
vector<int> hw;

int robotIdx = 0, hwIdx = 0;

int main(int argc, char** argv)
{
    cin >> n >> k;

    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') {
            hw.push_back(i);
        }
        else if (s[i] == 'P') {
            robot.push_back(i);
        }
    }

    while (true) {
        if (robotIdx == robot.size() || hwIdx == hw.size()) break;

        //범위 내
        if (abs(robot[robotIdx] - hw[hwIdx]) <= k) {
            ret++;
            robotIdx++; hwIdx++;
        }
        //범위 밖
        else {
            if (robot[robotIdx] < hw[hwIdx])
                robotIdx++;
            else
                hwIdx++;
        }

    }

    cout << ret;


    return 0;
}