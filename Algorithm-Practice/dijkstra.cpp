#include <iostream>

using namespace std;

int number = 6;
int INF = 1000000000; // int 형 - 10억

// 전체 그래프를 초기화한다.
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0},
};
bool v[6]; // 방문한 노드
int d[6]; // 최단 거리

// 가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallIndex() {
    int min = INF;
    int index = 0;
    for(int i=0; i<number; i++) {
        if(d[i]<min && !v[i]) {
            min = d[i];
            index = i;
        }
    }
    return index;
}

// 다익스트라를 수행하는 함수입니다.
// 이 알고리즘은 선형 탐색 - 즉 시간 복잡도 : O(N^2)
// 정점의 갯수가 많은데 간선은 적을 때 치명적일 정도로 비효율적으로 작동할 수 있다.
void dijkstra(int start) {
    for(int i=0; i<number; i++) {
        d[i] = a[start][i];
    }
    v[start] = true;
    for(int i=0; i<number-2; i++) {
        int current = getSmallIndex(); // 시간복잡도 O(N^2)
        v[current] = true;
        for(int j=0; j<6; j++) {
            // 이 부분이 어렵다. 
            if(!v[j]) {
                if(d[current]+a[current][j] < d[j]) {
                    d[j] = d[current] + a[current][j];
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dijkstra(0);
    for(int i=0; i<number; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}