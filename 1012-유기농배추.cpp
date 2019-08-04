#include <iostream>

using namespace std;

int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};
int grid[51][51];
bool visited[51][51];
int row, col, cnt;

void dfs(int a, int b) {
    visited[a][b] = true;

    for(int i=0; i<4; i++) {
        int tmp_x = a + dx[i];
        int tmp_y = b + dy[i];
        if(tmp_x<0 || tmp_y<0 || tmp_x >= row || tmp_y >= col) 
            continue;
        if(!visited[tmp_x][tmp_y] && grid[tmp_x][tmp_y]) {
            dfs(tmp_x, tmp_y);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;
    while(testcase--) {
        int answer = 0;
        cin >> row >> col >> cnt;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                grid[i][j] = 0;
                visited[i][j] = false;
            }
        }

        for(int i=0; i<cnt; i++) {
            int x, y;
            cin >> x >> y;
            grid[x][y] = 1;
        }
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    answer++;
                }       
            }
        }

        cout << answer << "\n";
    }

    return 0;
}