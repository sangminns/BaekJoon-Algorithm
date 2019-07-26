#include <iostream>
#include <vector>
#include <string>

using namespace std;

string w_grid[8] = {"WBWBWBWB",
                    "BWBWBWBW",
                    "WBWBWBWB",
                    "BWBWBWBW",
                    "WBWBWBWB",
                    "BWBWBWBW",
                    "WBWBWBWB",
                    "BWBWBWBW"};
string b_grid[8] = {"BWBWBWBW",
                    "WBWBWBWB",
                    "BWBWBWBW",
                    "WBWBWBWB",
                    "BWBWBWBW",
                    "WBWBWBWB",
                    "BWBWBWBW",
                    "WBWBWBWB"};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<char> > grid(n, vector<char>(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }

    int answer = 2501;
    for(int s=0; s<=n-8; s++) {
        for(int t=0; t<=m-8; t++) {
            int idx = 0;
            int idx2 = 0;
            int w_cnt = 0;
            int b_cnt = 0;
            for(int i=s; i<s+8; i++, idx++) {
                for(int j=t; j<t+8; j++, idx2++) {
                    if(grid[i][j] != w_grid[idx%8][idx2%8]) {
                        w_cnt++;
                    }
                    if(grid[i][j] != b_grid[idx%8][idx2%8]) {
                        b_cnt++;
                    }
                }
            }
            if(w_cnt < b_cnt) {
                if(answer > w_cnt) answer = w_cnt;
            } else {
                if(answer > b_cnt) answer = b_cnt;
            }
        }
    }   

    cout << answer;

    return 0;
}