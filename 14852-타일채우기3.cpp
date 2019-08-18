#include <iostream>

using namespace std;

// 점화식
// 정확히 나눌 수 있는 구간이 존재하지 않는 경우도 고려해야한다.
// 길이가 4가지 이상인 경우 특수한 경우 2가지가 추가 된다.
// D[n] = D[n-1]*2 + D[n-2]*3 + (D[n-3]*2 + D[n-4]*2 + D[0]*2)
// 시간 초과 발생 : 시간복잡도가 O(n^2)
// 따라서 2차원 다이나믹 프로그래밍 기법 사용 - O(n)

// int d[1000001];
long long int d[1000001][2];

/*
int dp(int x) {
    if(x==0) return 1;
    if(x==1) return 2;
    if(x==2) return 7;
    if(d[x]!=0) return d[x];
    int result = 3*dp(x-2) + 2*dp(x-1);
    for(int i=3; i<=x; i++) {
        result += (2*dp(x-i))%1000000007;
    }
    return d[x] = result%1000000007;
}
*/
long long int dp(int x) {
    d[0][0] = 0;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 1;
    for(int i=3; i<=x; i++) {
        d[i][1] = (d[i-1][1] + d[i-3][0])%1000000007;
        d[i][0] = (3*d[i-2][0] + 2*d[i-1][0] + 2*d[i][1])%1000000007;
    }
    return d[x][0];
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