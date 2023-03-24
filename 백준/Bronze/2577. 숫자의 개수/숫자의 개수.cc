#include <stdio.h>

int len(int n)
{
    int i = 0;
    while (n > 0)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

int main(void)
{
    int a, b, c, n;
    scanf("%d %d %d", &a, &b, &c);
    n = a * b * c;
    int arr[len(n)];
    int num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = len(n); i > 0; i--)
    {
        arr[i - 1] = n % 10;
        for (int j = 0; j < 10; j++)
        {
            if (arr[i - 1] == j)
                num[j]++;
        }
        n = n / 10;
    }
    for (int k = 0; k < 10; k++)
        printf("%d\n", num[k]);
}