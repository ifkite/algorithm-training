#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 16
#define MAGICNUM 6174
#define CHK_SIZE 10
int cmpStrInc(const void *pa, const void *pb){
    char *p1 = (char*)pa;
    char *p2 = (char*)pb;
    return *p1 - *p2;
}
int cmpStrDec(const void *pa, const void *pb){
    char *p1 = (char*)pa;
    char *p2 = (char*)pb;
    return *p2 - *p1;
}
int main(){
    char chNum[MAX_SIZE];
    int smallNum = 0, greatNum = 0, result = 0; 
    gets(chNum);
    //bugs here, original requirement: terminate when inputting -1
    int dealTime;
    char resultCh[MAGICNUM];
    while(chNum[0] != '-'){
		printf("N=%s:\n", chNum);
		dealTime = 0;
        if(strlen(chNum) != 4)
            printf("No!!\n");
        else{
			while(1){
				qsort(&chNum[0], strlen(chNum), sizeof(chNum[0]), cmpStrDec);
				greatNum = atoi(chNum);
				/*check num start*/
				int iter, flag = 0;
				for(iter = 0; iter < CHK_SIZE; ++iter){
					if(greatNum == 1111 * iter){
						flag = 1;
						break;
					} 
				}
				if(flag){
					printf("No!!\n");
					break;
				}
				/*check num end*/
				qsort(&chNum[0], strlen(chNum), sizeof(chNum[0]), cmpStrInc);
				smallNum = atoi(chNum);
				result = greatNum - smallNum;
				printf("%d-%d=%d\n", greatNum, smallNum, result);
				sprintf(chNum, "%d", result);
				++dealTime;
				if(result == MAGICNUM || result == 0){
					printf("Ok!! %d times\n", dealTime);
					break;
				} 
			}

        }
                
        gets(chNum);
    }
    return 0;
}

//test data start
/*
5364
2221
4444
234
7819
13234
0987
8908
1000
-1
*/
//test data end
