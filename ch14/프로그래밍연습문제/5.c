#include <stdio.h>
#include <string.h>

int main(void) 
{
  char ary[10][20];

  int i = 0;
  while(i<10)
  {
    char temp[20];
    printf("단어입력 (종료는 end 입력) :");
    scanf("%s",&temp);
    if(strcmp(temp,"end")==0) break;
    strcpy(ary[i],temp);
    i++;
  }
  printf("# 총 %d개의 단어가 입력되었습니다!\n",i);

  while(1)
  {
    char search[20];
    printf("검색 단어 (종료는 end 입력) : ");
    scanf("%s",&search);
    if(strcmp(search,"end")==0) break;
    int j;
    for(j = 0; j<i; j++)
    {
        if(strcmp(search,ary[j])==0) break;
    }
    if(j==i)
    {
      printf("# 없는 단어입니다.\n");
    }
    else
    {
      printf("%d번째 같은 단어가 있습니다!\n",j+1);
    }
  }

  return 0;
}