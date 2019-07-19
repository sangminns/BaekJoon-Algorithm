#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int max_func(int a, int b) {
    if(a>b) return a;
    else return b;
}

int solution(vector<vector<int> > triangle) {
    int answer = 0;
    vector<vector<int> > sum(triangle.size(), vector<int>(triangle.size())); 
    int len = sum.size();
    for(int i=0; i<len; i++) {
        for(int j=0; j<sum[0].size(); j++) {
            if(i<j)
                break;
            if(i==0 && j==0)
                sum[i][j] = triangle[0][0];
            else if(j==0)
                sum[i][j] = sum[i-1][j] + triangle[i][j];
            else if(i==j)
                sum[i][j] = sum[i-1][j-1] + triangle[i][j];
            else 
                sum[i][j] = max_func(sum[i-1][j-1] + triangle[i][j], sum[i-1][j] + triangle[i][j]);   
        }
    }
    
    for(int i=0; i<sum[len-1].size(); i++) {
        answer = max_func(answer, sum[len-1][i]);
    }
    
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int> > arr(n, vector<int>(n));
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << solution(arr);
    
    return 0;
}