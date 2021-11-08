#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
bool compareStringWithLocalVariable(char* S, char * T) {
    int lengthS = strlen(S);

    // declare result with length+1
    // in clang need extra \0 to store array data
    char resultS[lengthS+1]; 
    {
        int j = 0;

        for (int i=0; i<lengthS; i++) {
            if (S[i] != '#') {
                resultS[j] = S[i];
                j = j+1;
            } else {
                // greater than 0
                if (j > 0) {
                    j = j-1;
                }
            }
        }
    }

    int lengthT = strlen(T);
    char resultT[lengthT+1];
    {
        int j = 0;

        for (int i=0; i<lengthS; i++) {
            if (T[i] != '#') {
                resultT[j] = T[i];
                j = j+1;
            } else {
                // greater than 0
                if (j > 0) {
                    j = j-1;
                }
            }
        }
    }

    // printf("%s \n", resultS);
    // printf("%s \n", resultT);

    return strcmp(resultS, resultT) == 0;
}
*/

char* process(char* arr) {

    int lengthArr = strlen(arr);
    // assign memory to result array
    // use free method to release memory when process
    // char* resultArr = malloc(sizeof(char)*(lengthArr+1));
    // char* resultArr = arr;
    int j = 0;
    for (int i=0; i<lengthArr; i++) {
        // printf("%c %c \n", arr[i], arr[j]);
        // printf("%d %d \n", i, j);
        if (arr[i] != '#') {
            arr[j] = arr[i];
            j = j+1;
        } else {
            if (j > 0) {
                j = j-1;
            }
        }
    }

    printf("last j: %d \n", j);

    // cut rest of array
    arr[j] = '\0';

    return arr;
}


bool backspaceStringCompare(char* S, char* T) {
    
    return strcmp(process(S), process(T)) == 0;
}

int main() {
    /**
     *          ab#c
     * i          ^
     * j         ^
     * result   ac/0
     */
    char S[20] = "abb##c"; //{'a', 'b', '#', 'c'}; //"ab#c";
    char T[20] = {'a', 'c', '\0'}; //"ac";

    // printf("Test");


    bool result = backspaceStringCompare(S, T);

    printf("result: %d", result);

    return 0;
}
