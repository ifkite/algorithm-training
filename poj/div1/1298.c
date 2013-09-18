#include <stdio.h>
#include <string.h>
#define CMD_SIZE 24
#define DATA_SIZE 4096
int main(){
    const char cmd[CMD_SIZE] = {"ENDOFINPUT\0"};
    char input_cmd[CMD_SIZE];
    char data[DATA_SIZE];
    //bzero(input_cmd,CMD_SIZE);
    //bzero(data,DATA_SIZE);
    char cipher;
    int data_tail = 0;
    while(scanf("%s",input_cmd), strcmp(input_cmd,cmd)){//get 'STAR'
        getchar();//get \n
        //deal with cipher
        while((cipher = getchar()) != '\n'){
            if(isupper(cipher)){
                if(cipher > 'E')
                    data[data_tail] = cipher - 5;
                else
                    data[data_tail] = cipher + 21;
            }
            else
                data[data_tail] = cipher;
            ++data_tail; 
        }
        //put \n into data
        data[data_tail] = cipher;
        ++data_tail;
        //get 'END' 
        scanf("END");
        getchar();
    }
    int i;
    for(i = 0; i < data_tail; ++i)
        printf("%c", data[i]);
    return 0;
}
