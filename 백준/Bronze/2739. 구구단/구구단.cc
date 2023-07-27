#include <stdio.h>

int main(void)
{
    int num;

    scanf("%d", &num);
    if (0 < num && num < 10)
    {
        for(int i = 1; i < 10; i++)
        {
            printf("%d * %d = %d\n", num, i, num * i);
        }
    }
}