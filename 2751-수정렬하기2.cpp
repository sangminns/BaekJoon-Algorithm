#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge(int a[], int m, int middle, int n, int sorted[]) { // 배열, 시작점, 중간점, 끝점, 정렬배열
    int i = m;
    int j = middle+1;
    int k = m;
    // 작은 순서대로 배열에 삽입
    while(i <= middle && j <= n) {
        if(a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    // 남은 데이터도 삽입
    if(i > middle) {
        for(int t=j; t<=n; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else {
        for(int t=i; t<=middle; t++) {
            sorted[k] = a[t];
            k++;
        }
    }
    // 정렬된 배열을 삽입
    for(int t=m; t<=n; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort(int a[], int m, int n, int sorted[]) {
    // 크기가 1보다 큰 경우
    if(m < n) {
        int middle = (m+n)/2;
        mergeSort(a, m, middle, sorted);
        mergeSort(a, middle+1, n, sorted);
        merge(a, m, middle, n, sorted);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> num;
    int data[num];
    int sorted[num];

    for(int i=0; i<num; i++) {
        cin >> data[i];
    }
    mergeSort(data, 0, num-1, sorted);
    for(int i=0; i<num; i++) {
        cout << data[i] << " ";
    }
    
    return 0;
}