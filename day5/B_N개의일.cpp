#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int used[10];
int p[10];
int t[10][10];
int minV;

void npr(int n, int k, int m);

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			used[i] = 0; // used 초기화
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &t[i][j]);
			}
		}
		minV = 0x7fffffff; // 부호를 제외하고 모든 비트가 1인값...
		// minV = 100;
		npr(0, N, N);
		printf("#%d %d\n", tc, minV);
	}
}

void npr(int n, int k, int m)
{
	if (n == k)
	{
		int s = 0;
		for (int i = 0; i < k; i++) // i번 일에 대해
		{
			s += t[p[i]][i]; // p[i] 사람이 i번 일을 하는 시간
		}
		if (minV > s)
			minV = s; // N개의 일을 처리하는 최소 시간
	}
	else
	{
		for (int i = 0; i < m; i++) // 사용하지 않은 숫자를 찾음
		{
			if (used[i] == 0)
			{
				used[i] = 1; // a[i]를 사용함으로 표시
				p[n] = i; // a[i]를 선택
				npr(n + 1, k, m); // 다음 자리 숫자를 선택하러 이동
				used[i] = 0; // a[i]를 다른 자리에서 사용할 수 있도록
			}
		}
	}
}
