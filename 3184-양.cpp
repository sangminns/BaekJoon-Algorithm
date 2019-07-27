// 6 6
// ...#..
// .##v#.
// #v.#.#
// #.o#.#
// .###.#
// ...###

#include <iostream>
#include <vector>

using namespace std;

int row, col;
char grid[251][251];
bool check[251][251];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int sheep = 0;
int wolf = 0;

void dfs(int x, int y) {
    check[x][y] = true;

    if(grid[x][y]=='o') sheep++;
    else if(grid[x][y]=='v') wolf++;

    for (int i=0; i<4; i++) {
        int tmp_x = x + dx[i];
        int tmp_y = y + dy[i];
        if ((tmp_x < 0) || (tmp_y < 0) ||
            (tmp_x >= row) || (tmp_y >= col))
            continue;
        if(!check[tmp_x][tmp_y] && grid[tmp_x][tmp_y]!='#') 
            dfs(tmp_x, tmp_y);
        
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int live_sheep = 0;
    int live_wolf = 0;

    cin >> row >> col;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> grid[i][j];
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(!check[i][j] && grid[i][j]!='#') {
                sheep = 0;
                wolf = 0;
                dfs(i, j);
                if(sheep > wolf) {
                    live_sheep += sheep;
                } else {
                    live_wolf += wolf;
                }
            }
        }
    }

    cout << live_sheep << " " << live_wolf;

    return 0;
}