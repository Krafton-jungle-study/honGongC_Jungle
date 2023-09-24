#include <stdio.h>
    
int main() {

    int ary[5][6] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}
    };
    
    for(int i=0;i<4;i++)
    {
        int sum = 0;
        for(int j=0;j<5;j++)
        {
            sum+=ary[i][j];
        }   
        ary[i][5] = sum;
    }

    for(int i=0;i<6;i++)
    {
        int sum = 0;
        for(int j=0;j<4;j++)
        {
            sum+=ary[j][i];
        }
        ary[4][i] = sum;
    }

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<6;j++)
        {
            printf("%5d ",ary[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}