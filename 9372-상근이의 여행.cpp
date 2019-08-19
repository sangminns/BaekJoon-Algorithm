#include <iostream>
#include <vector>

using namespace std;

class Edge {
public:
    int node[2]; // 연결된 각각의 노드
    Edge(int a, int b) {
        this->node[0] = a;
        this->node[1] = b;
    }
};

// 부모 노드를 찾는 함수
int getParent(int parent[], int x) {
    if(parent[x] == x) return x; // 재귀함수의 종료 부분
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a < b) parent[b] = a; // 작은 값으로 합친다
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인 = 같은 그래프에 속해있는지 
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if(a == b) return 1;
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;
    while(testcase--) {
        int n, m;
        cin >> n >> m;
        vector<Edge> v;
        for(int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back(Edge(a, b));
        }
        // 각 정점이 포함된 그래프가 어디인지 저장
        int parent[n];
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        int sum = 0;
        for(int i=0; i<v.size(); i++) {
            // 사이클이 발생하지 않는 경우 그래프에 포함
            if(!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)) {
                sum++;
                unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
            } 
        }

        cout << sum << "\n";
    }

    return 0;    
}