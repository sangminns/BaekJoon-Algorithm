#include <iostream>

using namespace std;

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
    int parent[11];
    for(int i=1; i<=10; i++) {
        parent[i] = i;
    }
    // 두 가지 그래프 집합이 만들어진다.
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));

    unionParent(parent, 1, 5);
    // 연결 처리 - 1과 6을 연결하도 5와 연결 되어있다고 확인 가능 
    printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));

    return 0;
}
