#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i=0; i<n; i++) {
        cin >> vec[i];
    }

    for(int i=0; i<vec.size(); i++) { 
        stack<char> s;
        bool flag = false;
        for(int j=0; j<vec[i].size(); j++) { 
        
            if(vec[i][j]=='(') {
                s.push(vec[i][j]);
            } else {
                if(!s.empty())
                    s.pop();
                else {
                    flag = true;
                    break;
                }
            }
        }
        if(s.empty() && !flag) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}