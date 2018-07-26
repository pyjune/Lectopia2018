#include <stdio.h>

int map[10][10];

void find(int r, int c, int N, int M, int s); // r, c 현재위치, s 지나온 칸의 합계
int minV = 0x7fffffff;
int cnt;
int main(void)
{
	int T;
	int N, M;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		minV = 0x7fffffff;
		find(0, 0, N, M, 0);
		if (minV == 0x7fffffff)
			minV = 0;
		printf("#%d %d\n", tc, minV);
	}
}

void find(int r, int c, int N, int M, int s)
{
	cnt++;
	if (r == N - 1 && c == M - 1) // 도착
	{
		s += map[N - 1][M - 1];
		if (minV > s)
			minV = s;
	}
	else if (s >= minV)
		return;
	else
	{
		// 오른쪽
		if ((c+1<M) && (map[r][c+1]!=0))
			find(r, c + 1, N, M, s + map[r][c]);
		// 아래
		if ((r + 1 < N) && (map[r+1][c]!=0))
			find(r + 1, c, N, M, s + map[r][c]);
	}
}
