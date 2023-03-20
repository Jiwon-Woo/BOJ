#include <stdio.h>

void star(int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= i; j++)
			printf("*");
		for (int j = i + 1; j <= 2 * n - i; j++)
			printf(" ");
		for (int j = 2 * n - i + 1; j <= 2 * n; j++)
			printf("*");
		printf("\n");
	}

	for (int i = 1; i <= 2 * n; i++)
		printf("*");

	for (int i = n - 1; i >= 1; i--)
	{
		printf("\n");
		for (int j = 1; j <= i; j++)
			printf("*");
		for (int j = i + 1; j <= 2 * n - i; j++)
			printf(" ");
		for (int j = 2 * n - i + 1; j <= 2 * n; j++)
			printf("*");
	}

	printf("\n");
}

int main(void)
{
	int n;

	scanf("%d", &n);

	star(n);
}