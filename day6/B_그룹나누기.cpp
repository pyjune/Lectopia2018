#include <stdio.h>

int p[101];

int rep(int n);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		
		int N, M;
		scanf("%d %d", &N, &M);
		// 대표원소 초기화..
		for (int i = 1; i <= N; i++)
			p[i] = i;
		// M번 입력
		for (int i = 0; i < M; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			p[rep(n2)] = rep(n1);
		}
		// 대표원소의 총 개수
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			if (i == p[i])
				cnt++;
		}
		printf("#%d %d\n", tc, cnt);
	}
}

int rep(int n)
{
	while (n != p[n])
	{
		n = p[n];
	}
	return n;
}
