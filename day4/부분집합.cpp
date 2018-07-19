#include <stdio.h>

int L[3];
int A[] = { 1,2,3 };

void f(int n, int k);

int main(void)
{
	f(0, 3);
}
void f(int n, int k)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++) // L[i]가 1인 경우 A[i] 출력
		{
			if (L[i] == 1)
				printf("%d", A[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			L[n] = i;
			f(n + 1, k);
		}
		/*
		L[n] = 0;
		f(n + 1, k);
		L[n] = 1;
		f(n + 1, k);
		*/
	}
}
