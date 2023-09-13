#include <stdio.h>

void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);

int main(void)
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    print_nums(lotto_nums);
    return 0;
}

void input_nums(int *lotto_nums)
{
    int c;
    int overlap;
    for (int i = 0; i < 6; i++)
    {
        do
        {
            overlap = 0;
            printf("번호 입력 : ");
            scanf("%d", &c);
            for (int j = 0; j < i; j++)
            {
                if (lotto_nums[j] == c)
                {
                    printf("같은 번호가 있습니다!\n");
                    overlap = 1;
                    break;
                }
            }
            if (overlap == 0)
                lotto_nums[i] = c;
        } while (overlap == 1);
    }
}