#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    int i;

    // 2、3、4...12
    int ans[11] = {0};
    
    for (i=0; i<=100000; i++) {
        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int sum = dice1 + dice2;
        // reindex the answer array
        ans[sum-2] +=  1;
    }

    for (i=2; i<=12; i++) {
        // reindex the answer array
        printf("%d %d\n", i, ans[i-2]);
    }

    return 0;
}