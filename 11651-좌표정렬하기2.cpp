#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> p[100001];

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) 
        return a.first < b.first;
    else 
        return a.second < b.second;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;
    for(int i=0; i<testcase; i++) {
        int x, y;
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }
    
    sort(p, p+testcase, compare);

    for(int i=0; i<testcase; i++) {
        cout << p[i].first << " " << p[i].second << "\n";
    }

    return 0;
}