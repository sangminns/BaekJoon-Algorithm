#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
int grid[101][101];
bool check[101][101];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int cnt[101][101];

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    check[x][y] = true;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(a==n-1 && b==m-1) {
            return;
        }
        for(int i=0; i<4; i++) {
            int tmp_x = a + dx[i];
            int tmp_y = b + dy[i];
            int c = grid[tmp_x][tmp_y];
            if((tmp_x < 0) || (tmp_y < 0) || (tmp_x >= n) || (tmp_y >= m))
                continue;
            if(!check[tmp_x][tmp_y] && c==1) {
                q.push(make_pair(tmp_x, tmp_y));
                check[tmp_x][tmp_y] = true;
                cnt[tmp_x][tmp_y] = cnt[a][b] + 1;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &grid[i][j]);
        }
    }
    cnt[0][0] = 1;
    bfs(0, 0);
    cout << cnt[n-1][m-1];

    return 0;
}