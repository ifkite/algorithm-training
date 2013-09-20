#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_SIZE 16
void reverse(char *str,int strLen){
    int iter;
    for(iter = 0; iter < strLen / 2; ++iter){
        char tmp;
        tmp = str[iter];
        str[iter] = str[strLen-1-iter];
        str[strLen-1-iter]=tmp;
    }
}
int main(){
    int intCmd;
    scanf("%d", &intCmd);
    while(intCmd--){
        char chNumA[NUM_SIZE];
        char chNumB[NUM_SIZE];
        char chResult[NUM_SIZE];
        int intNumA, intNumB, result;
        scanf("%s %s", chNumA, chNumB);
        intNumA = atoi(chNumA);
        intNumB = atoi(chNumB);
        sprintf(chNumA, "%d", intNumA);
        sprintf(chNumB, "%d", intNumB);
        reverse(chNumA, strlen(chNumA));
        reverse(chNumB, strlen(chNumB));
        intNumA = atoi(chNumA);
        intNumB = atoi(chNumB);
        result = intNumA + intNumB;
        sprintf(chResult, "%d", result);
        reverse(chResult, strlen(chResult));
        printf("%d\n", atoi(chResult));
    }
    return 0;
}
//test data start
/*
5
24 1
4358 754
305 794
0002 0100
0050 0063
*/

//output
/*
34
1998
1
3
14
*/
