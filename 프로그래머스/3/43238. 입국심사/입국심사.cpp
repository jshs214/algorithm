#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<int> v;
int N;

bool check(ll T){
    
    ll ans = 0;
    for(int i = 0; i < v.size() ; i ++){
        ans +=  (T / (ll)v[i] );
    }
    
    return (ans >= N) ? true: false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    N = n;
    sort(times.begin(), times.end());
    v = times;
    
    ll l = 1;
    ll r = (ll)n * v[v.size()-1];
    
    while(l <= r){
        ll mid = (l + r) /2;
        
        if(check(mid) ){
            r = mid -1;
            answer = mid;
        }else
            l = mid +1;
        
    }
    
    
    
    return answer;
}