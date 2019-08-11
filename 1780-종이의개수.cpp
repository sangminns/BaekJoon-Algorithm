#include <iostream>

using namespace std;

int grid[2188][2188];
int ans_1 = 0;
int ans0 = 0;
int ans1 = 0;

void devideConquer(int s_row, int s_col, int num) {
    bool check = false;
    int tmp = grid[s_row][s_col];
    for(int i=s_row; i<s_row+num; i++) {
        for(int j=s_col; j<s_col+num; j++) {
            if(tmp != grid[i][j]) {
                check = true;
                break;
            }
        }
        if(check) break;
    }
    if(check) {
        num /= 3;
        devideConquer(s_row, s_col, num);
        devideConquer(s_row, s_col+num, num);  
        devideConquer(s_row, s_col+num*2, num);
        devideConquer(s_row+num, s_col, num);
        devideConquer(s_row+num, s_col+num, num);
        devideConquer(s_row+num, s_col+num*2, num);
        devideConquer(s_row+num*2, s_col, num);
        devideConquer(s_row+num*2, s_col+num, num);
        devideConquer(s_row+num*2, s_col+num*2, num);
    } else {
        if(tmp == -1) ans_1++;
        else if(tmp == 0) ans0++;
        else ans1++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    devideConquer(0, 0, n);

    cout << ans_1 << "\n" << ans0 << "\n" << ans1;

    return 0;
}