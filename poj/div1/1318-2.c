#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DICT_SIZE 101
#define STR_SIZE 7
int cmpStr(const void *pa, const void *pb){
    char *p1 = (char*)pa;
    char *p2 = (char*)pb;
    return *p1 - *p2;
}
int cmpDict(const void *pa, const void *pb){
    char *p1 = (char*)pa;
    char *p2 = (char*)pb;
    return strcmp(p1,p2);
}
int main(){
    char dict[DICT_SIZE][STR_SIZE];
    char data[DICT_SIZE][STR_SIZE];
    char str[STR_SIZE];
    char endStr = "XXXXXX";
    int dictTail = 0;
    gets(str);
    while(str[0] != 'X'){
        ////strncpy(data[dictTail], str, strlen(str) + 1);
        ////qsort(&str[0], strlen(str), sizeof(str[0]), cmpStr);//sort characters in word
        strncpy(dict[dictTail], str, strlen(str) + 1);
        ++dictTail;
        gets(str);
	}
    qsort(&dict[0], dictTail, sizeof(dict[0]), cmpDict);
    gets(str);
    while(str[0] != 'X'){
        qsort(&str[0], strlen(str), sizeof(str[0]), cmpStr);//sort characters in word
        int iter;
        int flag;
        char tmp[STR_SIZE];
        for(iter = 0, flag = 0; iter < dictTail; ++iter){
            strncpy(tmp,dict[iter], strlen(dict[iter]) + 1);
            qsort(&tmp[0], strlen(tmp),sizeof(tmp[0]), cmpStr);
            if(!strcmp(str, tmp)){
                printf("%s\n",dict[iter]);
                flag = 1; 
            }
        }
        if(!flag)
            printf("NOT A VALID WORD\n******\n");
        else
           printf("******\n");
        gets(str);
    }
    return 0;
}
