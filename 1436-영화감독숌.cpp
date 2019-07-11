#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    int tmp = 665;
    string str;
    while(num) {
        tmp++;
        str = to_string(tmp);
        if (str.find("666") == string::npos) {
            continue;
        } else {
            num--;
        }
    }   

    cout << tmp;

    return 0;
}

   