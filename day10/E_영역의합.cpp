// s[i][j]를 구할 때 m[i][j]를 더하는걸 빠뜨렸었네요..

#include <stdio.h>

int m[501][501];
int s[501][501]; // 1,1부터 i,j까지의 합

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		int k = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				m[i][j] = (k++) % 10 + 1;
			}
		}
		s[1][1] = m[1][1];
		for (int i = 2; i <= N; i++)
		{
			s[1][i] = s[1][i - 1] + m[1][i];
			s[i][1] = s[i - 1][1] + m[i][1];
		}
		for (int i = 2; i <= N; i++)
		{
			for (int j = 2; j <= N; j++)
			{
				s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1] + m[i][j];
			}
		}
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int r1, c1, r2, c2;
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			sum += (s[r2][c2] - s[r1 - 1][c2] - s[r2][c1 - 1] + s[r1 - 1][c1 - 1]);
		}
		printf("#%d %d\n", tc, sum);
	}
}
