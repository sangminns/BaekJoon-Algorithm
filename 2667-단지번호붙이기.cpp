// 7
// 0110100
// 0110101
// 1110101
// 0000111
// 0100000
// 0111110
// 0111000

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};
int n;
int grid[26][26];
bool check[26][26];
int num = 0;

void dfs(int x, int y) {
    if(grid[x][y]) {
        num++;
    }
    check[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int tmp_x = x + dx[i];
        int tmp_y = y + dy[i];
        if ((tmp_x < 0) || (tmp_y < 0) ||
            (tmp_x >= n) || (tmp_y >= n))
            continue;
        if(!check[tmp_x][tmp_y] && grid[tmp_x][tmp_y]) {
            dfs(tmp_x, tmp_y);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    vector<int> answer;
    int cnt = 0;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        for(int j=0; j<n; j++) {
            grid[i][j] = str[j]-48;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!check[i][j] && grid[i][j]) {
                dfs(i, j);
                answer.push_back(num);
                num = 0;
                cnt++;
            }
        }
    }
    cout << cnt << endl; 
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}