// 5
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR

// 4 3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num;
int grid[101][101];
int grid2[101][101];
bool check[101][101];
bool check2[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer, answer2;

void dfs(int x, int y) {
    check[x][y] = true;

    for(int i=0; i<4; i++) {
        int tmp_x = x + dx[i];
        int tmp_y = y + dy[i];
        if(tmp_x < 0 || tmp_y < 0 || tmp_x >= num || tmp_y >= num)
            continue;
        if(!check[tmp_x][tmp_y] && grid[x][y]==grid[tmp_x][tmp_y]) {
            dfs(tmp_x, tmp_y);
        }
    }

}

void dfs2(int x, int y) {
    if(check2[x][y]) return;
    check2[x][y] = true;

    for(int i=0; i<4; i++) {
        int tmp_x = x + dx[i];
        int tmp_y = y + dy[i];
        if(tmp_x < 0 || tmp_y < 0 || tmp_x >= num || tmp_y >= num)
            continue;
        if(!check2[tmp_x][tmp_y] && grid2[x][y]==grid2[tmp_x][tmp_y])
            dfs2(tmp_x, tmp_y);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;

    char arr[num][num];

    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            cin >> arr[i][j];
            if(arr[i][j]=='R' || arr[i][j]=='G') {
                grid[i][j] = 0;
            } else {
                grid[i][j] = 1;
            }
            if(arr[i][j]=='R') {
                grid2[i][j] = 0;
            } else if(arr[i][j]=='G') {
                grid2[i][j] = 1;
            } else {
                grid2[i][j] = 2;
            }
        }
    }

    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            if(!check[i][j]) {
                dfs(i, j);
                answer++;
            }
            if(!check2[i][j]) {
                dfs2(i, j);
                answer2++;
            }
        }
    }
    cout << answer2 << " " << answer;
    return 0;
}