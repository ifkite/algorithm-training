#include <stdio.h>
#define LINESIZE 25
#define SETSIZE 14
int main(){
    int lineSize;
    scanf("%d", &lineSize);
    while(lineSize){
        int lineCount = 0;
        int xArrcount[SETSIZE];
        while(lineCount != lineSize){
            char ch;
            int iter, chCount;
            //count num of X in each line
            for(iter = 0, chCount = 0; iter < LINESIZE; ++iter){
                ch = getchar();
                if(ch == 'X')
                    ++chCount; 
            }
            xArrcount[lineCount] = chCount;
            getchar();
            ++lineCount;
        }
        
        int xMaxNum = xArrcount[0];
        int iterMax;
        //find max counts of x for each data set 
        for(iterMax = 1; iterMax < lineSize; ++iterMax){
            if(xMaxNum < xArrcount[iterMax]) 
                xMaxNum = xArrcount[iterMax];
        }
        int result;
        for(iterMax = 0, result = 0; iterMax < lineSize; ++iterMax){
            result += xMaxNum - xArrcount[iterMax];
        }

        printf("%d\n", result);
        scanf("%d", &lineSize);
    }
}

//test data start
/*
4
XXXX                XXXXX
XXX               XXXXXXX
XXXXX                XXXX
XX                 XXXXXX
2
XXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
1
XXXXXXXXX              XX
0
*/

//output
/*
4
0
0
*/
