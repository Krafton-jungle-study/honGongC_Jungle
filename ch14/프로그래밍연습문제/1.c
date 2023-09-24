#include <stdio.h>

int main(void) {
  int ary[4][5];

  for (int i = 0; i < 4; i++) {
    printf("정수 5개를 입력하세요:");
    scanf("%d%d%d%d%d", ary[i] + 0, ary[i] + 1, ary[i] + 2, ary[i] + 3,
          ary[i] + 4);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%5d ", ary[i][j]);
    }
    printf("\n");
  }

  return 0;
}