#include <stdio.h>
#include <string.h>
#define STR_SIZE 7
#define DICT_SIZE 100
int main(){
    int arrStrLen[DICT_SIZE] = {0};
    int dictTail = 0;
    char dict[DICT_SIZE][STR_SIZE];
    char str[STR_SIZE];
    int strSize = STR_SIZE;
    char *endStr = "XXXXXX\0";
    ////while(getline(&str, strSize, stdin), strcmp(str,endStr))
    //deal with input
    //dictionary
    ////fgets(str, STR_SIZE, stdin);//will read '\n'
    gets(str);//will not read '\n'
    while(strcmp(str,endStr)){
        strncpy(dict[dictTail], str, strlen(str) + 1);
        arrStrLen[dictTail] = strlen(dict[dictTail]);
        ////fgets(str, STR_SIZE, stdin);
        gets(str);
        ++dictTail;
    }
    
    //cipher
    int loopVar;
    ////fgets(str, STR_SIZE, stdin);
    gets(str);
    //deal with input, and handle data
    int flags[STR_SIZE] = {0};
    int isFind;
    while(strcmp(str, endStr)){
        isFind = 0;
        for(loopVar = 0; loopVar < dictTail; ++loopVar){
            int strLen = strlen(str);
            //find the word that has the same length
            if(arrStrLen[loopVar] == strLen){
                int wordPoint;
                //find whether all characters exist or not
				int findChNum = strLen;
                for(wordPoint = 0; wordPoint < strLen; ++wordPoint){
                    int iter;
                    //initlize flags
                    for(iter = 0; iter < STR_SIZE; ++iter)
                        flags[iter] = 0;
                    for(iter = 0; iter < strLen; ++iter){
                        if(str[wordPoint] == dict[loopVar][iter] && !flags[iter]){
                            flags[iter] = 1;
                            --findChNum;
                            break;
                        }
                    }
                    //in dict, the word only matches with length
                    if(iter == strLen && !flags[strLen - 1])
                        break;
                    //find the word
                    if(!findChNum){
                        printf("%s\n", dict[loopVar]);
                        isFind = 1;
                    }
                }
            }
        }
        if(loopVar == dictTail && isFind) 
            printf("******\n");
        if(loopVar == dictTail && !isFind){
            printf("NOT A VALID WORD\n");
			printf("******\n");
        }
	    ////fgets(str, STR_SIZE, stdin);
        gets(str);
    }
    return 0;
}
