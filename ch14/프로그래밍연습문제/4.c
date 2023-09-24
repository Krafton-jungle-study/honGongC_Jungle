#include <stdio.h>
#include <string.h>

int main(void) {

  double ary1[4] = {1.5, 2.3, 7.7, 4.9};
  double ary2[4] = {3.4, 5.2, 4.0, 9.1};
  double ary3[4] = {0.3, 7.2, 8.4, 6.6};
  char *aryname[3] = {"첫","두","세"};

  double *ary[3] = {ary1, ary2, ary3};

  double max=0;
  int maxi=0;
  for(int i=0; i<3; i++)
  {
    double sum = 0;
    for(int j = 0; j<4; j++)
    {
      sum+=ary[i][j];
    }
    if(sum>max)
    {
      max = sum;
      maxi = i;
    }
  }

  printf("%s 번째 배열:",aryname[maxi]);
  for(int i=0; i<4; i++)
  {
    printf("%5.1lf",ary[maxi][i]);
  }
  printf("\n평균: %.1f",max/4.0);
  
  return 0;
}