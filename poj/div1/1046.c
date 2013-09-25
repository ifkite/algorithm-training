#include <stdio.h>
#include <math.h>
#define COL_SIZE 255
#define DICT_SIZE 16
typedef struct Rgb{
    int red;
    int green;
    int blue; 
}Rgb;
int main(){
    int iter;
    Rgb rgbDict[DICT_SIZE];
    for(iter = 0; iter < DICT_SIZE; ++iter)
       scanf("%d %d %d", &rgbDict[iter].red, &rgbDict[iter].green, &rgbDict[iter].blue);
    Rgb rgbInput;
    double tmp;
    double minDist;
    int minPos; 
    while(1){
        scanf("%d %d %d", &rgbInput.red, &rgbInput.green, &rgbInput.blue);
        if(rgbInput.red == -1)
            break;
        for(iter = 0, minPos = 0, minDist = sqrt(3 * COL_SIZE * COL_SIZE); iter < DICT_SIZE; ++iter){
            tmp = sqrt(pow(rgbInput.red - rgbDict[iter].red,2) + pow(rgbInput.green - rgbDict[iter].green,2) + pow(rgbInput.blue - rgbDict[iter].blue,2));
            if(tmp < minDist){
                minDist = tmp;
                minPos = iter;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n", rgbInput.red, rgbInput.green, rgbInput.blue, rgbDict[minPos].red, rgbDict[minPos].green, rgbDict[minPos].blue);
    }
    return 0;
}
