#include <stdio.h>
#include <string.h>

void reverse(char *s, int start, int end)
{
    end--;
    // [start, end)
    while(start < end) {
        char t = s[start];
        s[start] = s[end];
        s[end] = t;
        start++;
        end--;
    }
}

void reverseWithStar(char* start, char* end)
{
    end--;
    while(start < end)
    {
        char t = *start;
        *start = *end;
        *end = t;
        start++;
        end--;
    }
}

char * stringShift(char* s, int** shift, int shiftSize, int * shiftColSize)
{
    int len = strlen(s);

    int totalAmount = 0;

    for (int i=0; i<shiftSize; i++) {
        int direction = shift[i][0];
        int amount = shift[i][1];

        amount = amount % len;

        if (direction == 0) {
            amount = amount;
        } else {
            amount = len - amount;
        }

        totalAmount = totalAmount + amount;
    }

    totalAmount %= len;

    reverseWithStar(s, s+totalAmount);
    reverseWithStar(s+totalAmount, s+len);
    reverseWithStar(s, s+len);

    // reverse(s, 0, totalAmount);
    // reverse(s, totalAmount, len);
    // reverse(s, 0, len);


    // copy string to temp variable
    // char t[len];
    // for (int i=0; i<len; i++) {
    //     t[i] = s[i];
    // }

    // for (int i=0; i<len; i++) {
    //     // printf("%c", t[i+totalAmount]);
    //     s[i] = t[(i+totalAmount)%len];
    // }


    // for (int k=0; k<=totalAmount; k++) {
    //     char temp = s[0];
    //     for (int j=0; j<len-1; j++) {
    //         s[j] = s[j+1];
    //     }

    //     s[len-1] = temp;
    // }

    // for (int i=0; i<shiftSize; i++) {

    //     int direction = shift[i][0];
    //     int amount = shift[i][1];

    //     if (direction == 0) {
    //         for (int k=1; k<=amount; k++) {
    //             int temp = s[0];
    //             for (int j=0; j<len-1; j++) {
    //                 s[j] = s[j+1];
    //             }

    //             s[len-1] = temp;
    //         }
    //     } else {
    //         for (int k=1; k<=amount; k++) {
    //             char temp = s[len-1];
    //             for (int j=len-1; j>0; j--) {
    //                 s[j] = s[j-1];
    //             }

    //             s[0] = temp;
    //         }
    //     }
    // }
    
    // for (int i=0; i<shiftSize; i++) {

    //     int len = strlen(s);

    //     // 從第0列開始取代，所以要保存第0列的值，保存完之後，接到字串的最後方
    //     char temp = s[0];
    //     // j    
    //     // j+1  e
    //     for (int j=0; j<len-1; j++) {
    //         // printf("s %d %c \n", j, s[j]);
    //         s[j] = s[j+1];
    //     }

    //     s[len-1] = temp;
    //     // int temp[len];
    //     // printf("%d", len);
    // }

    return s;
}

int main()
{
    char s[] = "testing";

    int shift[3][2] = {1,2,0,4,1,6};
    int *ptr[3] = {shift[0], shift[1], shift[2]};

    int shiftSize = 3;
    int shiftColSize[3] = {1, 2, 0};

    // printf("%d", &shift[0][0]);
    // return 0;

    stringShift(s, ptr, shiftSize, shiftColSize);

    printf("result: %s", s);
    return 0;
}