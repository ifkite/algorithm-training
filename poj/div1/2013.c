#include <stdio.h>
#include <string.h>
#define SET_SIZE 16
#define STR_SIZE 32
int main(){
   int intCmd;
   scanf("%d",&intCmd);
   int setNum = 1;
   while(intCmd){
       int iter;
       char chSet[SET_SIZE][STR_SIZE];
       char str[STR_SIZE];
       int arrHead = 0, arrTail = intCmd - 1;
       for(iter = 0; iter < intCmd; ++iter){
           scanf("%s",str);
           if(iter % 2 == 0){
               strncpy(chSet[arrHead], str, strlen(str) + 1);
               chSet[arrHead][strlen(str)] = '\0';
               ++arrHead;
           }
           else{
               strncpy(chSet[arrTail], str, strlen(str) + 1);
               chSet[arrTail][strlen(str)] = '\0';
               --arrTail;
           }
       }
       printf("SET %d\n",setNum);
       for(iter = 0; iter < intCmd; ++iter)
           printf("%s\n",chSet[iter]);
       ++setNum;
       scanf("%d", &intCmd);
   }
   return 0;
}

//test data start
/*
7
Bo
Pat
Jean
Kevin
Claude
William
Marybeth
6
Jim
Ben
Zoe
Joey
Frederick
Annabelle
5
John
Bill
Fran
Stan
Cece
0
*/
//test data end
