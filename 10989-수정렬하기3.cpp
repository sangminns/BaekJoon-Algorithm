#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // n은 10000보다 작거나 같다는 범위 조건이 주어져있다. - 계수정렬
    int n;
    // 전역변수는 자동으로 초기화되지만 지역변수는 초기화되지 않는다.
    int a[10001] = {0}; // 0으로 자동으로 초기화

    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    for(int i=0; i<10001; i++) {
        while(a[i] != 0) {
            cout << i << "\n";
            a[i]--;
        }
    }

    return 0;
}