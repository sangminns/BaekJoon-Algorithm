#include <iostream>
#include <string>

using namespace std;

int n;
int grid[65][65];

void devideConquer(int x, int y, int num) {
    bool check = false;
    int tmp = grid[x][y];
    for(int i=x; i<x+num; i++) {
        for(int j=y; j<y+num; j++) {
            if(tmp != grid[i][j]) {
                check = true;
                break;
            }
        }
        if(check) break;
    }
    if(check) {
        num /= 2;
        cout << "(";
        devideConquer(x, y, num);
        devideConquer(x, y+num, num);
        devideConquer(x+num, y, num);
        devideConquer(x+num, y+num, num);
        cout << ")";
    } else {
        cout << tmp;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%1d", &grid[i][j]);
        }
    }

    devideConquer(0, 0, n);

    return 0;
}