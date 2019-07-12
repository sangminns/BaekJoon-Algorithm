#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while(1) {
        stack<char> s;
        getline(cin, str);
        bool flag = false;
        // cin >> str;
        if(str[0]=='.' && str.length()==1) break;

        for(int i=0; i<str.length(); i++) {
            if(str[i]=='(' || str[i]=='[') {
                s.push(str[i]);
            } else if(str[i]==')' || str[i]==']') {
                if(!s.empty()) {
                    if(s.top()=='(' && str[i]==')') {
                        s.pop();
                    } else if(s.top()=='[' && str[i]==']') {
                        s.pop();
                    } else {
                        flag = true;
                        break;
                    }
                } else {
                    flag = true;
                    break;
                }
            } 
        }
        if(s.empty() && !flag) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
   
    return 0;
}