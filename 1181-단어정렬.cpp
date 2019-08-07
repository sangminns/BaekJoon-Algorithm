#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b) {
    // 길이가 짧은 순서가 우선
    if(a.length() < b.length()) {
        return 1;
    } else if(a.length() > b.length()) {
        return 0;
    } 
    // 길이가 같은 경우라면
    else {
        return a < b; // 사전 순으로 정렬
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string arr[20001];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }    

    sort(arr, arr+n, compare);

    for(int i=0; i<n; i++) {
        if(i>0 && arr[i] == arr[i-1]) {
            continue;
        } else {
            cout << arr[i] << "\n";
        }
    }

    return 0;
}