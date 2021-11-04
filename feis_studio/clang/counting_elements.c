#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


// warning implicit declaration is invalid 
// https://stackoverflow.com/questions/8440816/warning-implicit-declaration-of-function
int countElement(int* arr, int arrSize);

int calculateArrayValueNumbers(int* arr, int arrSize);

int main() {
    // int data[] = {1, 3, 2, 3, 5, 0};
    int data[] = {1, 1, 1, 3, 3 ,3, 4};
    int length = (sizeof data) / (sizeof data[0]);

    int result = countElement(data, length);

    printf("%d \n", result);

    // int calculatedResult = calculateArrayValueNumbers(data, length);

    return 0;
}

bool isFound(int plusX1, int* arr, int arrSize) {
    bool result = false;
    for (int j=0; j<arrSize; j++) {
        // printf("%d: %d %d \n", i, currentValue, plus1[i]);
        if (arr[j] == plusX1) {
            result = true;
            break;
        }
    }
    return result;
}

int calculateArrayValueNumbers(int* arr, int arrSize) {
    int numberOfX[1002] = {0};

    for (int i=0; i<arrSize; i++) {
        numberOfX[arr[i]] = numberOfX[arr[i]] + 1;
    }

    for (int i=0; i<10; i++) {
        printf("%i: %d \n", i, numberOfX[i]);
    }

    return 0;
}

int cmp(const void* a, const void* b) {
    return * (const int*)a - *(const int*)b;
}

int countElement(int* arr, int arrSize) {
    // Constraint
    // arrSize >=1 && arrSize <=1000
    // arr[i] >=0 && arr[i] <= 1000
    
    // arr:   [1, 1, 1, 3 ,3 ,3, 4]
    // i-1     ^
    // i          ^
    // number: 1  2  3  1   2  3  1
    // count:  0  0  0  0   0  0  3

    qsort(arr, arrSize, sizeof(int), cmp);

    int count = 0;
    int number = 1;
    for (int i=1; i<arrSize; i++) {
        // printf("%d \n", arr[i]);
        if (arr[i] != arr[i-1]) {
            if (arr[i] == arr[i-1] + 1) {
                count = count + number;
            }
            number = 1;
        } else {
            number = number + 1;
        }
    }

    // to avoid undefined value in array set all default value equals false
    // space: O(range) => 1002(constraint)
    // Time: O(arrSize, range)
    /**
    bool found[1002] = {false};

    // set each found value from array
    // method 2:
    for (int i=0; i<arrSize; i++) {
        found[arr[i]] = true;
    }

    int count = 0;
    for (int i=0; i<arrSize; i++) {
        int plus1 = arr[i] + 1;
        if (found[plus1]) {
            count = count + 1;
        }
    }
    */

    // Input:
    // arr: [1, 3, 2, 3, 5, 0], arrSize = 6
    // plus: 2  4  3  4  6  1
    // found: 1  0  1  0  0  1
    // count: 1  1  2  2  2  3
    // O(arrSize * arrSize)
    // method 1:
    /**
    int found[arrSize];
    int count = 0;
    for (int i=0; i<arrSize; i++) {
        int plusX1 = arr[i] + 1;
        if (isFound(plusX1, arr, arrSize)) {
            count = count + 1;
        }
    }
    */

    return count;
}