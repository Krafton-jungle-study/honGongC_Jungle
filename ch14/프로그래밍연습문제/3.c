#include <stdio.h>
#include <string.h>

int main(void) {

  char *word[3] = {"가위","바위","보"};

  int num=0;
  do
  {
    printf("정수 입력:");
    scanf("%d",&num);
    if(num==-1)break;
    num-=1;
    num%=3;
    printf("%s\n",word[num]);
  }while(1);
  return 0;
}