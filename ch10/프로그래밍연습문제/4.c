#include <stdio.h>

int check_same(int *, int *);

int main(void)
{
    int lotto_nums[6] = {4, 10, 25, 30, 41, 45};
    int my_nums[6] = {1, 4, 7, 22, 41, 43};

    printf("일치하는 번호의 개수 : %d", check_same(lotto_nums, my_nums));

    return 0;
}

int check_same(int *lotto_nums, int *my_nums)
{
    int cnt = 0;

    for (int i = 0; i < 6; i++) // 배열의 size는 함수 안쪽에서 구할 수 없다.
    {
        for (int j = 0; j < 6; j++)
        {
            if (my_nums[i] == lotto_nums[j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}