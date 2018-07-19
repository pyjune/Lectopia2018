#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int L[100];
int cnt;
void f(int n, int k, int x);

int main(void)
{
	int T;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, X;
		scanf("%d %d", &N, &X);
		cnt = 0;
		f(0, N, X);
		printf("#%d %d\n", tc, cnt);

	}
}

void f(int n, int k, int x)
{
	if (n == k)
	{
		int s = 0;
		for (int i = 0; i < k; i++)
			if (L[i] == 1)
				s += i + 1;
				//printf("%d ", i + 1); // 부분집합을 출력하는 경우
		//printf("\n");
		if (s == x)
			cnt++;
	}
	else
	{
		L[n] = 0;
		f(n + 1, k, x);
		L[n] = 1;
		f(n + 1, k, x);
	}
}
