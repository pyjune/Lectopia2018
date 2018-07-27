#include <stdio.h>

int map[21][21];
int d[21][21];

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				d[i][j] = 0;
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (i == 1 && j == 1)
					d[i][j] = 1;
				else
				{
					for (int l = 1; l < i; l++)
					{
						if (map[i-l][j] == l)
							d[i][j] += d[i-l][j];
					}
					for (int l = 1; l < j; l++)
					{
						if (map[i][j - l] == l)
							d[i][j] += d[i][j - l];
					}
				}
			}
		}
		printf("#%d %d\n", tc, d[N][M]);
	}
}
