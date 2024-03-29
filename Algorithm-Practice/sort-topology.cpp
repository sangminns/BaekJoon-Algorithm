#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX]; // 진입 차수
vector<int> a[MAX];

void topologySort() {
    int result[MAX];
    queue<int> q;
    // 진입 차수가 0인 노드를 큐에 삽입합니다.
    for(int i=1; i<=n; i++) {
        if(inDegree[i] == 0) q.push(i);
    }
    // 위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문합니다.
    for(int i=1; i<=n; i++) {
        // n개를 방문하기 전에 큐가 빈다면 사이클이 발생합니다.
        if(q.empty()) {
            printf("사이클이 발생했습니다.");
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int i=0; i<a[x].size(); i++) {
            int y = a[x][i];
            if(--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
    for(int i=1; i<=n; i++) {
        printf("%d ", result[i]);
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    n = 7;
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(6);
    inDegree[6]++;
    a[5].push_back(6);
    inDegree[6]++;
    a[6].push_back(7);
    inDegree[7]++;
    
    topologySort();

    return 0;
}