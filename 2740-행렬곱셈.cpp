#include <iostream>
#include <vector>

using namespace std;

// 슈트라센 행렬곱셈 알고리즘
// https://ko.wikipedia.org/wiki/슈트라센_알고리즘

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;
    vector<vector<int> > arr1(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr1[i][j];
        }
    }

    int s, k;
    cin >> s >> k;
    vector<vector<int> > arr2(s, vector<int>(k));
    for(int i=0; i<s; i++) {
        for(int j=0; j<k; j++) {
            cin >> arr2[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            int tmp = 0;
            for(int t=0; t<m; t++) {
                tmp += arr1[i][t]*arr2[t][j];
            }
            cout << tmp << " ";
        }
        cout << "\n";
    }
    
    return 0;
}