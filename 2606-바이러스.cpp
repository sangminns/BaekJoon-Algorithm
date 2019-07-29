#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> *com, vector<bool> &c, int start) {
    queue<int> q;
    q.push(start);
    c[start] = true;
    while(!q.empty()) {
        int a = q.front();
        q.pop();
        // cout << a << " ";
        for(int i=0; i<com[a].size(); i++) {
            int b = com[a][i];
            if(!c[b]) {
                q.push(b);
                c[b] = true;
            }
        } 
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    int num, cnt;
    cin >> num;
    cin >> cnt;

    vector<int> computer[num+1];
    vector<bool> check(num+1, false);

    for(int i=0; i<cnt; i++) {
        int x, y;
        cin >> x >> y;
        computer[x].push_back(y);
        computer[y].push_back(x);
    }

    bfs(computer, check, 1);

    for(int i=0; i<check.size(); i++) {
        if(check[i])
            answer++;
    }

    cout << answer-1;

    return 0;
}