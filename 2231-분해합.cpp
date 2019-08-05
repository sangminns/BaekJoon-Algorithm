#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    // n :216 
    // i : 198
    for(int i=1; i<=1000000; i++) {
        int sum = i;
        int idx = i;
        while(idx>0) {
            int tmp = idx%10;
            sum += tmp;
            idx /= 10;
        }
        if(sum == n) {
            cout << i;
            break;
        } else if(n <= i) {
            cout << 0;
            break;
        }
    }

    return 0;
}