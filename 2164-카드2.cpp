#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int tmp;
    cin >> n;
    queue<int> q;
    for(int i=1; i<=n; i++) {
        q.push(i);
    }
    while(q.size()>1) {
        q.pop();
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    cout << q.front();
   
    return 0;
}