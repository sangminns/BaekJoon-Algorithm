// 10 4200
// 1
// 5
// 10
// 50
// 100
// 500
// 1000
// 5000
// 10000
// 50000

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int answer = 0;
    cin >> n >> k;
    vector<int> vec(n);
    int idx = n-1;

    for(int i=0; i<n; i++) {
        cin >> vec[i];
        if(k >= vec[i]) idx = i;
    }
 
    while(k>=0 && idx>=0) {
        if(k >= vec[idx]) {
            answer += k/vec[idx];
            k %= vec[idx];
        }
        idx--;
    }

    cout << answer;

    return 0;
}