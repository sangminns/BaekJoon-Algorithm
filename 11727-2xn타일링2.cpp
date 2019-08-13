#include <iostream>

using namespace std;


// 3가지 모양의 타일이 존재한다.
// D[n] = D[n-1] + 2*D[n-2];
int dp[1001];

int solution(int x) {
    if(x==1) return 1;
    if(x==2) return 3;
    if(dp[x] != 0) return dp[x];
    return dp[x] = (solution(x-1) + 2*solution(x-2))%10007;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result;
    cin >> n;

    result = solution(n);
    cout << result;

    return 0;
}