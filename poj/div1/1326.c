#include <stdio.h>
#include <string.h>
#define STR_SIZE 32
int main(){
    char cmd[STR_SIZE],cityName[STR_SIZE];
    char code;
    int miles = 0, result = 0;
    char term[2] = "#\0";
    char endline[2] = "0\0";
    while(1){
       scanf("%s", &cmd[0]);
       if(!strcmp(cmd, term))
           break;
       else if(!strcmp(cmd, endline)){
           getchar();
           printf("%d\n", result);
           result = 0;
       }
       else{
           scanf("%s %d %c", &cityName[0], &miles, &code);
           getchar();
           switch(code){
               case 'F':
                   result += miles * 2;
                   break;
               case 'B':
                   result =result + miles + (miles + 1) / 2;
                   break;
               case 'Y':
                   if(miles <= 500)
                       result += 500;
                   else
                       result += miles;
                   break;
           }
       }
    }
    return 0;
}
