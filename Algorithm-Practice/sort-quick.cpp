#include <iostream>

int number = 10;
int data[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end) {
    // 원소가 1개인 경우
    if(start >= end) {
        return;
    }

    int pivot = start; // 피벗은 첫 번째 원소
    int i = start + 1; // 왼쪽에서부터 작은 값을 찾는 출발 지점 
    int j = end; // 오른쪽에서부터 큰 값을 찾는 출발 지점
    int temp; // 값을 교환할 수 있는 변수 

    // 엇갈릴 때까지 반복
    while(i <= j) {
        // 피벗 값보다 큰 값을 만날 때까지
        while(data[i] <= data[pivot]) { // 이 부분 등호 바꾸면 내림차순(큰 값을 찾는 위치와 작은 값을 찾는 위치를 바꾸면 된다)
            i++;
        }
        // 피밧 값보다 작은 값을 만날 때까지
        while(data[j] >= data[pivot] && j > start) { // 이 부분 등호 바꾸면 내림차순
            j--;
        }
        // 현재 엇갈린 상태면 피벗 값 교체
        if(i > j) {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        } else {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }

    quickSort(data, start, j-1);
    quickSort(data, j+1, end);
}

int main(void) {

    quickSort(data, 0, number-1);
    for(int i=0; i<number; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}