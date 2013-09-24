#include <stdio.h>
#include <stdlib.h>
#define MAX_STR_SIZE 51
typedef struct Data{
    int oriIndex;
    int reverseNum;
}Data;
int cmpar(const void *pa, const void *pb){
    Data *p1 = (Data*)pa;
    Data *p2 = (Data*)pb;
    int result;
    result = p1->reverseNum - p2->reverseNum;
    if(result)
        return result;
    else
        return p1->oriIndex - p2->oriIndex;
    	
}
int getReverseNum(const char*str, int strLen){
    int cnt;
    int tmp[3] = {0};
    int iter;
    for(iter = strLen - 1; iter >= 0; --iter){
        switch(str[iter]){
            case 'A':
                tmp[0]++;
                tmp[1]++;
                tmp[2]++;
                break;
            case 'C':
                tmp[1]++;
                tmp[2]++;
                cnt += tmp[0];
                break;
            case 'G':
                tmp[2]++;
                cnt += tmp[1];
                break;
            case 'T':
                cnt += tmp[2];
                break;
            default:
                break;
        }
    }
    return cnt;
}

int main(){
    int strLen, lineNum;
    while(scanf("%d %d", &strLen, &lineNum) != EOF){
	char **input = (char **)malloc(sizeof(char*) * lineNum);/*alloc memory*/
    Data *pData = (Data*)malloc(sizeof(Data) * lineNum);
    int iter;                                    /*to store raw input data*/
    for(iter = 0; iter < lineNum; ++iter){
        input[iter] = (char*)malloc(sizeof(char) * strLen);
        scanf("%s", input[iter]);
        pData[iter].oriIndex = iter;
        pData[iter].reverseNum = getReverseNum(input[iter], strLen);/*take*/
    }                              /*care of '\0', but there's no bug here*/
    qsort(&pData[0], lineNum, sizeof(Data), cmpar);
    for(iter = 0; iter < lineNum; ++iter){
        printf("%s\n", input[pData[iter].oriIndex]);
    }
    for(iter = 0; iter < lineNum; ++iter)                    /*free memory*/
       free(input[iter]);
    free(input);
    free(pData);
    }
	
    return 0;
}
