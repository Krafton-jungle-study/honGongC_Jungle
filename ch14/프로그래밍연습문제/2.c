#include <stdio.h>
#include <string.h>

int main(void) {

  char word[5][20];
  printf("5개의 과일 이름 입력:");
  scanf("%s%s%s%s%s",word[0],word[1],word[2],word[3],word[4]);

  int max=strlen(word[0]);
  int maxi=1;
  for(int i=1;i<5;i++)
    {
      int clen = strlen(word[i]);
      if(max< clen)
      {
        max = clen;
        maxi = i;
      }
    }

  printf("길이가 가장 긴 과일 이름은 %s입니다.",word[maxi]);
  
  return 0;
}