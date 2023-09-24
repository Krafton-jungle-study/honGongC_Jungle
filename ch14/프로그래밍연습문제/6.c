#include <stdio.h>

void swap(int *, int *);
void printSales(int);  //지점별로 평균까지 출력

//함수에서 공통으로 쓰기 위해 전역변수로 선언
char *name[4]={"관악점","강남점","명동점","대림점"};
int sales[4][6] = {
    {70, 45, 100, 92, 150, 81},
    {88, 92, 77, 30, 52, 55},
    {50, 90, 88, 75, 77, 49},
    {120, 92, 80, 150, 130, 105}};
double mean[4];

int main(void) 
{
  //평균 입력
  int sum;
  for(int i=0;i<4;i++)
  {
    sum=0;
    for(int j=0;j<6;j++)
    {
      sum+=sales[i][j];
    }
    mean[i] = (double)sum/6.0;
  }

  //정렬
  int order[4]={0,1,2,3};
  int max;
  int maxi;
  for(int i=0;i<4;i++)
  {
    max=0;
    maxi=i;
    for(int j=i;j<4;j++)
    {
      int cmean = mean[order[j]];
      if(cmean>max)
      {
        max = cmean;
        maxi = j;
      }
    }
    if(maxi!=i) swap(order+i,order+maxi);
  }

  //실적벽 출력
  printf("실적별 출력...\n");
  for(int i=0;i<4;i++)
  {
    printSales(order[i]);
  }

  //지점별 출력
  printf("\n지점별 출력...\n");
  for(int i=0;i<4;i++)
  {
    printSales(i);
  }

  return 0;
}

void swap(int* a, int* b)
{
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void printSales(int i)
{
  printf("%s",name[i]);
  for(int j=0;j<6;j++)
  {
    printf("%5d",sales[i][j]);
  }
  printf("%5.0lf\n",mean[i]);
}