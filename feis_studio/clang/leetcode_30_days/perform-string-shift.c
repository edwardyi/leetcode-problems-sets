#include <stdio.h>

char * stringShift(char * s, int** shift, int shiftSize, int * shiftColSize)
{
    return "testing";
}

int main()
{
    char* s = "testing";
    int** shift[2][3] = {
        {1, 3, 3},
        {2, 4, 7},
        {1, 2, 8}
    };
    int shiftSize = 3;
    int* shiftColSize[3] = {1, 2, 0};

    stringShift(s, shift, shiftSize, shiftColSize);
    return 0;
}