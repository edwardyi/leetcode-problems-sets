#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int extractMaxData(int* data, int stoneSize) {

    // int size = sizeof(data[0]) / sizeof(int);
    // int size = sizeof(data);
    int maxValue = data[0];
    // printf("size: %d %lu %lu %d", size, sizeof(data), sizeof(int), data[3]);

    for (int i=1; i<stoneSize; i++) {
        // printf("data: %d", data[i]);
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }

    for (int i=0; i<stoneSize; i++) {
        if (data[i] == maxValue) {
            data[i] = 0;
            break;
        }
    }

    return maxValue;
}

int extractMaxDataByIndex(int* stones, int stoneSize) {
    int max_index = 0;
    // run through each value in array for searching max number
    for (int i=0; i<stoneSize;i++) {
        if (stones[i] > stones[max_index]) {
            max_index = i;
        }
    } 

    // in order to return max value from array to save max value first
    int maxValue = stones[max_index];

    // set zero for array
    stones[max_index] = 0;

    return maxValue;
}

int extractMaxByCounter(int* counter, int upperBound) {
    
    // 1000
    for (int i=upperBound; i>0; i--) {
        if (counter[i] > 0) {
            // substract 1 to remove array
            counter[i] = counter[i]-1;
            return i;
        }
    }

    return 0;
}

void insertByCounter(int* counter, int value) {
    counter[value] = counter[value] + 1;
}

void insert(int* stones, int stoneSizes, int value) {
    for (int i=0; i<stoneSizes; i++) {
        if (stones[i] == 0) {
            stones[i] = value;
            return;
        }
    }
}

int cmp (const void *a, const void *b) {
    return *(const int*)b - *(const int*)a;
}


int lastStoneWeight(int* stones, int stoneSize) {

    if (stoneSize < 2) {
        return stones[0];
    }

    int counter[1001] = {0};

    // stone number in counter
    for (int i = 0; i<stoneSize; i++) {
        counter[stones[i]] = counter[stones[i]]+1;
    }

    int upperBound = 1000;

    while(true) {
        // x is greater than y
        // int x = extractMaxData(stones, stoneSize);
        // int y = extractMaxData(stones, stoneSize);

        // int x = extractMaxDataByIndex(stones, stoneSize);
        // int y = extractMaxDataByIndex(stones, stoneSize);

        int x = extractMaxByCounter(counter, upperBound);
        int y = extractMaxByCounter(counter, upperBound);

        // printf("%d %d", x, y);
        // return 0;

        // time: O(nlogn)
        /**
        qsort(stones, stoneSize, sizeof(int), cmp);

        int x = stones[0];
        int y = stones[1];

        // qsort assign stones zero to avoid infinity loop
        stones[0] = stones[1] = 0;

        for (int i=0; i<stoneSize; i++) {
            printf("%d ", stones[i]);
        }
        */

        printf("-----\n");

        printf("x:%d y:%d ", x, y);

        if (y == 0) {
            return x;
        }

        // x is greater than y
        if (x != y) {
            // x-y > 0 ensure no negative number to insert to array
            // insert(stones, stoneSize,  x-y);
            insertByCounter(counter, x-y);
        }
    }

    return 0;
}

int main() {
    // int data[] = {8, 8, 99, 3, 6, 7, 8 ,1, 1, 1000};
    int data[] = {2, 7, 4, 1, 8, 1};
    // int data[] = {1};

    int size = sizeof(data)/sizeof(int);

    int result = lastStoneWeight(data, size);

    printf("result:%d", result);

    return result;
}
