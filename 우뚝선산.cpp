// 코드배틀27 No.2 
#include <stdio.h>

int h[50000];

int find(int n);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &h[i]);
		int r = find(N);
		printf("#%d %d\n", tc, r);
	}
}

int find(int n)
{
	int rising = 0;
	int falling = 0;
	int cnt = 0;
	int i = 1;
	while (i<n)
	{
		while ((h[i - 1] < h[i])&&(i<n))
		{
			rising++;
			i++;
		}
		while ((h[i - 1] > h[i]) && (i<n))
		{
			falling++;
			i++;
		}
		cnt += rising*falling;
		rising = 0;
		falling = 0;
	}
	return cnt;
}
