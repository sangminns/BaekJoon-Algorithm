#include <iostream>

using namespace std;

// 점화식 : D[n] = 3*D[n-2] , 짝수개일 경우는 특수한 경우 2가지가 추가된다. 
// D[n] = 3*D[n-2] + (2*D[n-4] + 2*D[n-6] + ... + 2*D[0])

int d[1001];

int dp(int x) {
    if(x==0) return 1;
    if(x==1) return 0;
    if(x==2) return 3;
    if(d[x]!=0) return d[x];
    int result = 3*dp(x-2);
    for(int i=3; i<=x; i++) {
        if(i%2==0) {
            result += 2*dp(x-i);
        }
    }
    return d[x] = result;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result;
    cin >> n;

    result = dp(n);
    cout << result;

    return 0;
}