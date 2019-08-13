#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, result = 0;
    cin >> n;
    result += n/500;
    n %= 500;
    result += n/100;
    n %= 100;
    result += n/50;
    n %= 50;
    result += n/10;
    cout << result; 

    return 0;
}