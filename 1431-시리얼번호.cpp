#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int getSum(string a) {
    int len = a.length(), sum = 0;
    for(int i=0; i<len; i++) {
        // 숫자인 경우에만 더합니다.
        if(a[i]-'0' <= 9 && a[i]-'0' >= 0) {
            sum += a[i]-'0';
        }
    }
    return sum;
}

bool compare(string a, string b) {
    // 길이가 짧은 순서가 우선
    if(a.length() < b.length()) {
        return 1;
    } else if(a.length() > b.length()) {
        return 0;
    } 
    // 길이가 같은 경우라면
    else {
        int aSum = getSum(a);
        int bSum = getSum(b);
        // 글자에 포함된 숫자의 합이 다르다면
        if(aSum != bSum) {
            return aSum < bSum;
        } else {
            return a < b;
        }
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
        cout << arr[i] << "\n";
    }

    return 0;
}