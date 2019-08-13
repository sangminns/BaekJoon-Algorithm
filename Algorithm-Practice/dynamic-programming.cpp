#include <iostream>

using namespace std;

int d[100];

// 피보나치 수

// 재귀함수 구현 : 시간복잡도 => O(2^n)
int dp(int x) {
    if(x==1) return 1;
    if(x==2) return 1;
    return dp(x-1) + dp(x-2);
}

// 메모이제이션 구현 : 시간복잡도 => O(n)
int dp_memoization(int x) {
    if(x==1) return 1;
    if(x==2) return 1;
    if(d[x] != 0) return d[x];
    return d[x] = dp(x-1) + dp(x-2);
} 

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    printf("%d\n", dp(3)); 

    printf("%d\n", dp_memoization(30));

    return 0;
}