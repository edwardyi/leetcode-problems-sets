#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int i, n[10], pos;
    for (i=1; i<=10; i++) {
        n[i-1] = i;
    }

    for (i=1; i<=10; i++) {
        pos = rand() % 10;
        int tmp = n[i-1];
        n[i-1] = n[pos];
        n[pos] = tmp;
        // printf("random position");
    }

    for (i=1; i<=10; i++) {
        printf("%d ", n[i-1]);
    }

    
    return 0;
}