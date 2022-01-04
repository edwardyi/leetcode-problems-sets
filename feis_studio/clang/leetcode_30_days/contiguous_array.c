#include <stdio.h>
#include <stdlib.h>

/**
 * nums:       [0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1]
 * j:           ^
 * count(0, j)  1  2  2  2  3  3  4  5  5  6  6(count how many zeros in number array)
 * count(2, 6) = count(0, 6) - count(0, 1) = 4 - 2 = 2
 * 
 * @param i
 * @param j 
 * @param nums 
 * @return int 
 */
int count0(int i, int j, int* nums) 
{
    int count = 0;
    for (int k=i; k<=j; k++) {
        if (nums[k] == 0) 
        {
            count++;
        }

        // printf("count(%d %d): %d \n", k, j, count);
    }

    return count;
}

int count1(int i, int j, int* nums)
{
    int count = 0;
    for (int k=i; k<=j; k++) {
        if (nums[k] == 1) 
        {
            count++;
        }
    }

    return count;
}

int diffCount(int j, int* nums)
{
    int diff = 0;

    for (int k=0; k<=j; k++) {
        if (nums[k] == 0) {
            diff++;
        } else {
            diff--;
        }

        // printf("diffCount: %d %d \n", k, diff);
    }

    return diff;
}

int findMaxJ(int* nums, int size, int target, int *countDiff)
{
    int maxJ = -1;
    // for(int j=i; j<size; j++) 
    for (int j=0; j<size; j++)
    {

        // if (diffCount(j, nums) == target) 
        if (countDiff[cindex(j)] == target)
        {
            if (j > maxJ) {
                printf("maxJ: %d %d \n", maxJ, j);
                maxJ = j;
            }
        }
        // if (count0(0, j, nums) - count0(0, i-1, nums) == count1(0, j, nums) - count1(0, i-1, nums)) 
        // if (count0(0, j, nums) - count1(0, j, nums) == count0(0, i-1, nums) - count1(0, i-1, nums)) 
        // if (diffCount(j, nums) == diffCount(i-1, nums))
        // {
        //     int length = j - i + 1;

        //     // printf("%d %d %d %d %d \n", length, j, i, count0, count1);

        //     if (length > maxLength) {
        //         maxLength = length;
        //     }
        // }

        // printf("diff count: %d %d %d %d %d %d \n", diffCount(j, nums), diffCount(i-1, nums), i, j, maxLength, diffCount(j, nums) == diffCount(i-i, nums));
        // printf("diff count: %d %d %d %d %d %d \n", j, i-1, diffCount(j, nums), diffCount(i-1, nums), maxLength, j - i + 1);
        // printf("diff count: %d %d %d  \n", j, i, j - i + 1);

        // int c0 = count0(i, j, nums);
        // int count0 = 0;
        // for (int k=0; k<=j; k++) {
        //     if (nums[k] == 0) 
        //     {
        //         count0++;
        //     }

        //     printf("count0(%d %d): %d \n", k, j, count0);
        // }

        // int c1 = count1(i, j, nums);

        // int c1 = 0;
        // for (int k=0; k<=j; k++) {
        //     if (nums[k] == 1) 
        //     {
        //         c1++;
        //     }
        // }

        // if (c0 == c1) {
        //     int length = j - i + 1;

        //     // printf("%d %d %d %d %d \n", length, j, i, count0, count1);

        //     if (length > maxLength) {
        //         maxLength = length;
        //     }
        // }
    }

    return maxJ;
}

int cindex (int j) {
    return j + 1;
}

int findMaxLength(int* nums, int size)
{
    // count diff array
    // biggest - smallest + 1 from range
    // (numsSize-1) - (-1) + 1
    int countDiffSize = size + 1;
    int countDiff[countDiffSize]; // countDiff range: -1 ~ numsSize -1 (depends on for loop start position)
                                  // actual array index: 0 ~ numsSize

    countDiff[cindex(-1)] = 0;

    for (int k=0; k<size; k++) 
    {
        if (nums[k] == 0) {
            countDiff[cindex(k)] = countDiff[cindex(k-1)] + 1;
        } else {
            countDiff[cindex(k)] = countDiff[cindex(k-1)] - 1;
        }
    }

    int maxLength = 0;
    for(int i=0; i<size; i++) 
    {
        // int target = diffCount(i-1, nums);
        int target = countDiff[cindex(i-1)];
        int maxJ = findMaxJ(nums, size, target, countDiff);

        int length = maxJ - i + 1;
        if (length > maxLength) {
            maxLength = length;
        }

    }



    return maxLength;
}


int main()
{
    printf("testing\n");

    int nums[] = {0, 1, 0};

    int length = (sizeof nums) / (sizeof nums[0]);

    int result = findMaxLength(nums, length);

    printf("result is %d", result);


    return 0;

}