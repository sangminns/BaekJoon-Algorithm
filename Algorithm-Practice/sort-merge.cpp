#include <iostream>

int number = 8;
int sorted[8]; // 정렬 배열은 반드시 전역 변수로 선언 - 불필요한 메모리 사용 최소화
// 함수 안에서 배열을 선언하면 매번 배열을 선언해야 한다.
// 기존에 데이터를 담을 추가적인 배열 공간이 필요하다는 점에서 메모리 활용이 비효율적이다. 

void merge(int a[], int m, int middle, int n) { // 배열, 시작점, 중간점, 끝점
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

void mergeSort(int a[], int m, int n) {
    // 크기가 1보다 큰 경우
    if(m < n) {
        int middle = (m+n)/2;
        mergeSort(a, m, middle);
        mergeSort(a, middle+1, n);
        merge(a, m, middle, n);
    }
}

int main(void) {

    int data[8] = {7, 6, 5, 8, 3, 5, 9, 1};
    mergeSort(data, 0, number-1);
    for(int i=0; i<number; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}