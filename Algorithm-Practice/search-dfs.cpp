#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; // 노드의 개수 
int c[7]; // 방문처리 
vector<int> a[8]; // 1~7까지의 노드 

// 재귀 함수 이용
void dfs(int x) {
	if(c[x]) return; // 노드를 방문했다면 return
    c[x] = true;
    cout << x << ' ';
    for(int i=0; i<a[x].size(); i++) {
        int y = a[x][i];
        dfs(y);
    } 
}
 
int main(void) {
    // 1과 2를 연결
    a[1].push_back(2);
    a[2].push_back(1);
    // 1과 3을 연결
    a[1].push_back(3);
    a[3].push_back(1);
    // 2와 3을 연결
    a[2].push_back(3);
    a[3].push_back(2);
    // 2와 4를 연결
    a[2].push_back(4);
    a[4].push_back(2);
    // 2와 5를 연결
    a[2].push_back(5);
    a[5].push_back(2);
    // 3과 6을 연결
    a[3].push_back(6);
    a[6].push_back(3);
    // 3과 7을 연결 
    a[3].push_back(7);
    a[7].push_back(3);

    dfs(1);

    return 0;
}
