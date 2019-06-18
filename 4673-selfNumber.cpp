#include <stdio.h>
#define MAX 10001

int selfNum(int num) {
    int sum = num;
    for(int i=0; i<4; i++) { 
        if(num == 0)
            break;
        else {
            sum += num % 10;
            num /= 10;
        }
    }
    return sum;
}

int main(void) {
    int arr[MAX] = {0,};
    for(int i=1; i<MAX; i++) {
        int key = selfNum(i);
        if(key < MAX) {
            arr[key] = 1;
        }
        // printf("%d\n", key);
        if(arr[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}

   