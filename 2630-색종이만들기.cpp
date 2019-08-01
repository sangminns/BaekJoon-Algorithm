// 8
// 1 1 0 0 0 0 1 1
// 1 1 0 0 0 0 1 1
// 0 0 0 0 1 1 0 0
// 0 0 0 0 1 1 0 0
// 1 0 0 0 1 1 1 1
// 0 1 0 0 1 1 1 1
// 0 0 1 1 1 1 1 1
// 0 0 1 1 1 1 1 1 

// 9 7 
   
#include <iostream>
#include <vector>

using namespace std;

int white = 0; // 0
int blue = 0; // 1

void devideConquer(vector<vector<int> > &arr, int s_row, int e_row, int s_col, int e_col, int num) {
    if(num < 1)
        return;
    int tmp = arr[s_row][s_col];
    bool check = false;
    for(int i=s_row; i<e_row; i++) {
        for(int j=s_col; j<e_col; j++) {
            if(tmp != arr[i][j]) {
                check = true;
                break;
            }
        }
        if(check)
            break;
    }
    if(!check) {
        if(tmp == 0) white++;
        else blue++;
        return;
    }
    devideConquer(arr, s_row, (s_row+e_row)/2, s_col, (s_col+e_col)/2, num/2); // [0][0] ~ [4][4]
    devideConquer(arr, s_row, (s_row+e_row)/2, (s_col+e_col)/2, e_col, num/2); // [0][4] ~ [4][8]
    devideConquer(arr, (s_row+e_row)/2, e_row, s_col, (s_col+e_col)/2, num/2); // [4][0] ~ [8][4]
    devideConquer(arr, (s_row+e_row)/2, e_row, (s_col+e_col)/2, e_col, num/2); // [4][4] ~ [8][8]
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;
    int num = n;
    vector<vector<int> > grid(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    devideConquer(grid, 0, n, 0, n, num);

    cout << white << "\n" << blue;

    return 0;
}