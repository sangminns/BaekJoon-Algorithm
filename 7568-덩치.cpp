#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int> > arr, int n) {
    
    for(int i=0; i<n; i++) {
        int cnt = 1;
        for(int j=0; j<n; j++) {
            if(i==j) continue;
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
                cnt++;
        }
        cout << cnt << " ";
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    vector<vector<int> > vec(num, vector<int>(2));

    for(int i=0; i<num; i++) {
        int a, b;
        cin >> a >> b;
        
        vec[i][0] = a;
        vec[i][1] = b;
    }

    solution(vec, num);

    return 0;
}