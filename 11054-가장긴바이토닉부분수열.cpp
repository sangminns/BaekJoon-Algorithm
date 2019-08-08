#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[1001];
    int front_dp[1001];
    int back_dp[1001];
    int max = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++) {
        front_dp[i] = 1;
        for(int j=0; j<=i; j++) {
            if(arr[i]>arr[j] && front_dp[i]<front_dp[j]+1) {
                front_dp[i]++;
            }
        }
    }

    for(int i=n-1; i>=0; i--) {
        back_dp[i] = 1;
        for(int j=n-1; j>=i; j--) {
            if(arr[i]>arr[j] && back_dp[i]<back_dp[j]+1) {
                back_dp[i]++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(max < front_dp[i]+back_dp[i])
            max = front_dp[i]+back_dp[i];
    }

    cout << max-1;

    return 0;
}