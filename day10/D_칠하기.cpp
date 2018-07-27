#include <stdio.h>

int d[101][4];
int cost[101][101];

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
			for (int j = 1; j <= 3; j++)
			{
				scanf("%d", &cost[i][j]); // i번 집을 j색으로 칠하는 비용
			}
		}
		d[1][1] = cost[1][1]; // 1번집을 1로 칠하는 비용
		d[1][2] = cost[1][2]; // 1번집을 2로 칠하는 비용
		d[1][3] = cost[1][3]; // 1번집을 3으로 칠하는 비용
		for (int i = 2; i <= N; i++)
		{
			d[i][1] = (d[i - 1][2] < d[i - 1][3] ? d[i - 1][2] : d[i - 1][3]) + cost[i][1];
			d[i][2] = (d[i - 1][1] < d[i - 1][3] ? d[i - 1][1] : d[i - 1][3]) + cost[i][2];
			d[i][3] = (d[i - 1][1] < d[i - 1][2] ? d[i - 1][1] : d[i - 1][2]) + cost[i][3];
		}
		int minV = d[N][1] < d[N][2] ? d[N][1] : d[N][2];
		minV = d[N][3] < minV ? d[N][3] : minV;
		printf("#%d %d\n", tc, minV);
	}
}
