#include <string>
#include <vector>

using namespace std;
int a[100004];

int solution(int n) {
    int answer = 0;
    
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    
    for(int i = 3; i <=n; i ++){
        a[i] = a[i-1] + a[i-2];
        a[i] %= 1234567;
    }
    
    answer = a[n];
    
    return answer;
}