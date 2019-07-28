#include <iostream>
#include <vector>

using namespace std;

int dp[301];
int stair[301];

int max_func(int a, int b) {
    if(a>b) return a;
    else return b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> stair[i];
    }
    int answer;
    // 마지막 계단을 밟기 이전의 경우
    // 1. 마지막 계단 전의 계단을 밟은 경우.
    // 2. 마지막 계단 전의 계단을 밟지 않은 경우.

    // 1. dp[n] = dp[n-3] + dp[n-1] + dp[n]
    // 2. dp[n] = dp[n-2] + dp[n]

    dp[0] = stair[0];
    dp[1] = max_func(stair[0]+stair[1], stair[1]);
    dp[2] = max_func(stair[0]+stair[2], stair[1]+stair[2]);
    for(int i=3; i<n; i++) {
        dp[i] = max_func(dp[i-3]+stair[i-1]+stair[i], dp[i-2]+stair[i]);
    }
    answer = dp[n-1];
    
    cout << answer;

    return 0;
}