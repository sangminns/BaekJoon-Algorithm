// 3
// 26 40 83
// 49 60 57
// 13 89 99

#include <iostream>
#include <vector>

using namespace std;

int min_func(int x, int y) {
    if(x > y) return y;
    else return x;
}

// Dynamic Programming
int rgb(vector<vector<int> > home, int num) {
    int a, b, c;

    if(num > 1) {
        for(int i=1; i<num; i++) {
            a = home[i-1][0];
            b = home[i-1][1];
            c = home[i-1][2];
            home[i][0] += min_func(b, c);
            home[i][1] += min_func(a, c);
            home[i][2] += min_func(a, b);
        }   
    }

    if(home[num-1][0] <= home[num-1][1] && home[num-1][0] <= home[num-1][2])
        return home[num-1][0];
    else if(home[num-1][1] <= home[num-1][0] && home[num-1][1] <= home[num-1][2])
        return home[num-1][1];
    else
        return home[num-1][2];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int> > vec(n, vector<int>(3));

    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> vec[i][j];
        }
    }

    cout << rgb(vec, n);

    return 0;
}