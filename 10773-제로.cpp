#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    int sum = 0;
    stack<int> s;
    cin >> k;

    while(k--) {
        int x;
        cin >> x;
        if(x==0) {
            s.pop();
        } else {
            s.push(x);
        }
    }
    
    while(!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum;
    
    return 0;
}

   