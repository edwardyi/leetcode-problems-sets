#include <stdio.h>
#include <stdlib.h>


int cmp (const void* a, const void* b) {

    int va = *(const int *) a;
    int vb = *(const int *) b;
    
    if (va % 2 == 0 && vb % 2 == 0) {
        return va - vb;
    }

    if (va % 2 == 1 && vb % 2 == 1) {
        return va - vb;
    }

    if (va % 2 == 1 && vb % 2 == 0) {
        return -1;
    }

    if (va % 2 == 0 && vb % 2 == 1) {
        return 1;
    }

    return 0;
    // a > b => +
    // a == b => 0
    // a < b => -
}


int main()
{
    int data[10] = {1, 8, 7, 3, 6, 4};

    qsort(data, 10, sizeof(int), cmp);

    for (int i=0; i<10; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}