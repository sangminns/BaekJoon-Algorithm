#include <iostream>

using namespace std;

// 피보나치 수열과 원리가 같다.
// C(N) = C(N-1) + C(N_2)
// C(N-1) : 가장 오른쪽에 세워진 막대 1개 제거
// C(N-2) : 가장 오른쪽에 세워진 막대 2개 제거

int dp[1001];

int solution(int n) {
    if(n<=2) return n;
    if(dp[n] != 0) return dp[n];
    return dp[n] = (solution(n-1)+solution(n-2))%10007;
}

int main(void) {

    int num, result;
    cin >> num;

    result = solution(num);
    cout << result;

    return 0;
}