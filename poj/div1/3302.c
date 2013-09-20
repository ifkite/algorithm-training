#include <stdio.h>
#include <string.h>
#define STR_SIZE 101
void reverse(char *chSrc, char *chRev, int strLen){
    int iter;
    for(iter = 0; iter < strLen; ++iter)
        chRev[iter] = chSrc[strLen-1-iter];
    chRev[strLen] = '\0';
    return;
}
int main(){
    int intCmd;
    scanf("%d", &intCmd);
    while(intCmd--){
        char chStrA[STR_SIZE];
        char chStrB[STR_SIZE];
        char chStrBRev[STR_SIZE];
        scanf("%s %s", chStrA, chStrB);
        int iter, pointerB, pointerBRev;
        int strLenB = strlen(chStrB);
        reverse(chStrB, chStrBRev, strLenB);
        for(iter = 0, pointerB = 0, pointerBRev= 0; iter < strlen(chStrA); ++iter){
            if(chStrA[iter] == chStrB[pointerB])     
                ++pointerB;
            if(chStrA[iter] == chStrBRev[pointerBRev])
                ++pointerBRev;
        }
        if(pointerB == strLenB || pointerBRev == strLenB)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

//test data
/*
5
arash aah
arash hsr
kick kkc
A a
a12340b b31
*/

//output
/*
YES
YES
NO
NO
YES
*/
