#include <stdio.h>

int main() {
    int arrs[10] = {0};
    int i,
        lower,
        upper;
    

    for (i=1; i<=10; i++) {
        printf("%d:", i);
        scanf("%d", &arrs[i-1]);
    }

    while (1) {
        
        printf("lower bound:");
        scanf("%d", &lower);

        printf("upper bound:");
        scanf("%d", &upper);
        
        if (lower == 0 && upper == 0) {
            break;
        }

        for (i=1; i<=10; i++) {
            if (lower <= arrs[i-1] && upper >= arrs[i-1]) {
                printf("%d ", arrs[i-1]);
            }
        }

        printf("\n");
    }

    return 0;
}