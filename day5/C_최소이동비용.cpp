#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t[11][11];
int used[11];
int p[11];
int minV;
void npr(int n, int k);

int main(void)
{
	int T;

	freopen("Text.txt", "r", stdin);

	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			used[i] = 0;
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &t[i][j]);
			}
		}
		minV = 0x7fffffff;
		used[1] = 1;
		p[0] = 1;
		npr(1, N);
		printf("#%d %d\n", tc, minV);
	}
}

void npr(int n, int k)
{
	if (n == k)
	{
		int s = 0;
		for (int j = 1; j < k; j++)
			s += t[p[j - 1]][p[j]];  // 사무실에서 순열에 따라 나무를 방문한 거리
		s += t[p[k - 1]][1]; // 마지막 나무에서 사무실로 가는 거리
		if (minV > s)
			minV = s;
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				p[n] = i;
				npr(n + 1, k);
				used[i] = 0;
			}
		}
	}
}
