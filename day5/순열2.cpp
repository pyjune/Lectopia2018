#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[] = { 1,2,3,4, 5 };
int used[5];
int p[3];

void npr(int n, int k, int m);

int main(void)
{
	npr(0, 3, 5);
}

void npr(int n, int k, int m)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < m; i++) // 사용하지 않은 숫자를 찾음
		{
			if (used[i] == 0)
			{
				used[i] = 1; // a[i]를 사용함으로 표시
				p[n] = a[i]; // a[i]를 선택
				npr(n + 1, k, m); // 다음 자리 숫자를 선택하러 이동
				used[i] = 0; // a[i]를 다른 자리에서 사용할 수 있도록
			}
		}
	}
}
