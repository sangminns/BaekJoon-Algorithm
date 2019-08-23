// '모든 임계 경로를 구해야 한다' - 역추적 필요

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

class Edge {
public:
    int node;
    int t;
    Edge(int node, int t) {
        this->node = node;
        this->t = t;
    }
};

int n, start, finish;
int inDegree[MAX], result[MAX], c[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX]; // 역추적하기 위해 사용

void topologySort() {
    queue<int> q;
    // 시작점 노드를 큐에 삽입합니다.
    q.push(start);
    // 더이상 방문할 노드가 없을 때까지
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i=0; i<a[x].size(); i++) {
            Edge y = Edge(a[x][i].node, a[x][i].t);
            if(result[y.node] <= y.t+result[x])
                result[y.node] = y.t+result[x];
            // 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다.
            if(--inDegree[y.node] == 0)
                q.push(y.node);
        }
    }
    // 결과를 역추적합니다.
    int count = 0;
    q.push(finish);
    while(!q.empty()) {
        int y= q.front();
        q.pop();
        for(int i=0; i<b[y].size(); i++) {
            Edge x = Edge(b[y][i].node, b[y][i].t);
            // 최장 경로에 포함되는 간선인지 확인합니다.
            if(result[y]-result[x.node] == x.t) {
                count++;
                // 큐에는 한 번씩 담아 추적합니다.
                if(c[x.node] == 0) {
                    q.push(x.node);
                    c[x.node] = 1;
                }
            }
        }
    }
    cout << result[finish] << "\n" << count; 
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, node, t;
        cin >> x >> node >> t;
        a[x].push_back(Edge(node, t));
        b[node].push_back(Edge(x, t));
        inDegree[node]++;
    }
    cin >> start >> finish;
    topologySort();

    return 0;
}