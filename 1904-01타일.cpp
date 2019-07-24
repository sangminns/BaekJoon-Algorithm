#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int tile[1000001];

    tile[0] = 1;
    tile[1] = 2;
    for(int i=2; i<n; i++) {
        tile[i] = (tile[i-1] + tile[i-2])%15746;
    }

    cout << tile[n-1];

    return 0;
}