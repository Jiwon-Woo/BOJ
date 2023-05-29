#include <stdio.h>

int flag[9] = {0, };
int arr[8] = {0, };
int num = 0;

void    combination(int n, int m, int number)
{
    if (m == 1)
    {
        arr[num] = number;
        for (int i = 0; i < 8; i++)
            if (arr[i] != 0)
                printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i > number && flag[i] == 0)
            {
                arr[num] = number;

                num++;
                flag[number] = 1;

                combination(n, m - 1, i);

                flag[i] = 0;
                num--;
            }
        }
    }
}

int     main(void)
{
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {   
        for (int j = 0; j <= 8; j++)
            flag[j] = 0;
        
        combination(n, m, i);
    }
}