#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int tmp, max = 0;
    bool flag = false;
    cin >> n >> m;

    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                tmp = arr[i] + arr[j] + arr[k];
                if(tmp==m) {
                    max = tmp;
                    flag = true;
                    break;
                } else if(tmp < m && max < tmp) {
                    max = tmp;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }

    cout << max;

    return 0;
}

   