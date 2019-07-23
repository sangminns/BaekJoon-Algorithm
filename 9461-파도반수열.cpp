#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase; 
    cin >> testcase;

    while(testcase--) {
        int n;
        cin >> n;
        unsigned long arr[101];
        arr[0] = 1;
        arr[1] = 1;
        arr[2] = 1;
        for(int i=3; i<n; i++) {
            arr[i] = arr[i-3] + arr[i-2];
        }

        cout << arr[n-1] << "\n";
    }
    
    return 0;
}