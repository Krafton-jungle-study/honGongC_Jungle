#include <stdio.h>

void reverse(double *ary, int size);

int main(void)
{
    double ary[] = {1.5, 20.1, 16.4, 2.3, 3.5};
    int size = sizeof(ary) / sizeof(double);
    reverse(ary, size);

    for (int i = 0; i < size; i++)
    {
        printf("%.1lf ", ary[i]);
    }

    return 0;
}

void reverse(double ary[], int size)
{
    double *pa = ary;
    double *pb = ary + (size - 1);
    double temp;

    while (pa < pb)
    {
        temp = *pa;
        *pa = *pb;
        *pb = temp;
        pa++;
        pb--;
    }
}