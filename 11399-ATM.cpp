#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    int sum = 0;
    int answer = 0;
    cin >> num;
    vector<int> vec(num);
    
    for(int i=0; i<num; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    for(int i=0 ;i<num; i++) {
        sum += vec[i];
        answer += sum;
    }

    cout << answer;

    return 0;
}