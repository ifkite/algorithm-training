#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

int main(){
    char *line = NULL;
    size_t num = 0;
    char *endInput = "ENDOFINPUT\n\0";
    char *start = "START\n\0";
    char *end = "END\n\0";
    int i;
    while(getline(&line, &num, stdin),strcmp(line,endInput)){
        if(strcmp(line, start) && strcmp(line, end)){
            for(i = 0; i < strlen(line); ++i){
                if(isupper(line[i])){
                    if(line[i] > 'E')
                        printf("%c", line[i] - 5);
                    else
                        printf("%c", line[i] + 21);
                }
                else
                    printf("%c", line[i]);
            }
        }
        else
            continue;
    }
    return 0;

}
