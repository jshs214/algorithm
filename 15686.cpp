#include <bits/stdc++.h>
using namespace std;

int n, m;


int a[55][55];

int result= 992819121;

vector<pair<int,int>> house;
vector<pair<int, int>> chicken;
vector<vector<int>> chickenList;


// (Chicken)C(m)
void combi(int start, vector<int> v) {
    if (v.size() == m){
        chickenList.push_back(v);
        return;
    }

    for (int i = start + 1; i < chicken.size(); i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }

    return;
}


int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j <n; j ++){
            cin >> a[i][j];
            if(a[i][j] == 1)
                house.push_back( {i, j} );
            if(a[i][j] ==2){
                chicken.push_back( {i, j} );
            }
        }
    }

    vector<int> v;
    combi(-1, v);

    // Chicken집 m개 combination만큼 Loop 
    for (auto cList : chickenList) {    // index

        int ret = 0;
        // 집 수만큼 Loop
        for (auto k: house) {
            int minValue = 992819121;

            //각각 치킨집 순회 후 min값 저장
            for (auto j : cList) {
                int dist = abs(k.first - chicken[j].first) + abs(k.second - chicken[j].second);
                minValue = min(minValue, dist);
            }
            ret += minValue;
        }

        result = min(result, ret);
    }
    cout << result << "\n";
    
    return 0;
}