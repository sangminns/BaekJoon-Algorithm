#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    
    for(int i=0; i<priorities.size(); i++) {
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    
    while(1) {
        int tmp_val = q.front().first;
        int tmp_idx = q.front().second;        
        if(pq.top() == tmp_val) {
            answer++;
            if(tmp_idx == location) {
                break;
            }
            pq.pop();
            q.pop();
        } else {
            q.pop();
            q.push(make_pair(tmp_val, tmp_idx));
        }
        
    }

    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;
    cin >> testcase;

    while(testcase--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        cout << solution(arr, m) << endl;
    }

    return 0;
}