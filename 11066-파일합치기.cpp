/*
알고리즘 
20132368 김 상 민
25. Merging Files
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int dp[501][501];
int num[501][501];
int cost[501];
int sum[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;
    
    while (testcase--) {
        int N;
        cin >> N;
        for (int i=1; i<=N; i++) {
            cin >> cost[i];
            sum[i] = sum[i-1] + cost[i];
        }
        for (int i = 1; i <= N; i++)
            num[i - 1][i] = i;
        for (int d = 2; d <= N; d++) {
            for (int i = 0; i + d <= N; i++) {
                int j = i + d;
                dp[i][j] = 2e9;
                for (int k = num[i][j - 1]; k <= num[i + 1][j]; k++) {
                    int v = dp[i][k] + dp[k][j] + sum[j] - sum[i];
                    if (dp[i][j] > v) {
                         dp[i][j] = v;
                        num[i][j] = k;   
                    }
                }
            }
        }
        cout << dp[0][N] << endl;
    }
    return 0;
}
 