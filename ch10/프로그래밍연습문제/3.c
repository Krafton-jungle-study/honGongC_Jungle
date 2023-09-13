#include <stdio.h>

void star(int);

int main(void)
{
    int score[5] = {72, 88, 95, 64, 100};
    int size = sizeof(score) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        star(score[i]);
    }
    return 0;
}

void star(int size)
{
    int cnt = size / 5;
    printf("(%3d) ", size);
    for (int i = 0; i < cnt; i++)
    {
        printf("*");
    }
    printf("\n");
}
