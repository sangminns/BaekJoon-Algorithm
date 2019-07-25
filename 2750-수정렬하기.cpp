#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    vector<int> data(num);

    for(int i=0; i<num; i++) {
        cin >> data[i];
    }
    
    sort(data.begin(), data.end());

    for(int i=0; i<num; i++) {
        cout << data[i] << "\n";
    }

    return 0;
}