#include <stdio.h>

int main(){
    int intOriStart, intOriEnd;
    while(scanf("%d %d", &intOriStart, &intOriEnd) != EOF){
        int intTmpStart, intTmpEnd, tmpResult, result;

        if(intOriStart > intOriEnd){
            intTmpStart = intOriEnd;
            intTmpEnd = intOriStart; 
        }
        else{
            intTmpStart = intOriStart;
            intTmpEnd = intOriEnd;
        }
         
        //avoid func calling in loop
        int tmp = intTmpStart;
        result = 1;//when terminated on 1, result can not increased
        while(tmp != 1){
			if(tmp % 2 == 0)
				tmp = tmp >> 1;
			else
                tmp = tmp * 3 + 1;
            ++result;
        }

        int iter; 
        if(intTmpStart != intTmpEnd){
            for(iter = intTmpStart + 1; iter <= intTmpEnd; ++iter){
                tmp = iter;
                tmpResult = 1;
                while(tmp != 1){
                    if(tmp % 2 == 0)
                        tmp = tmp >> 1;
                    else
                        tmp = tmp * 3 + 1;
					++tmpResult;
                }
                //always keep result storing max num
                if(tmpResult > result) 
                    result = tmpResult;
            }
        }

        printf("%d %d %d\n", intOriStart, intOriEnd, result);
    }
    return 0;
}

//test data
/*
1 10
100 200
201 210
150 150
1000 900
*/

//output
/*
1 10 20
100 200 125
201 210 89
150 150 16
1000 900 174
*/
