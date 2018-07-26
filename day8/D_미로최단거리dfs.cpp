#include <stdio.h>

int maze[100][100];

int find(int r, int c, int N);
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };
int minV;
void find2(int r, int c, int N, int k);

int main(void)
{
	int T;
	int N;
	int sr, sc; // 시작 좌표..
	
	freopen("Text.txt", "r", stdin);
	
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%1d", &maze[i][j]);
				if (maze[i][j] == 2) // 시작 좌표 찾기
				{
					sr = i;
					sc = j;
				}
			}
		}
		minV = N*N;
		find2(sr, sc, N, 0);
		//int r = find(sr, sc, N);
		printf("#%d %d\n", tc, minV-1);
	}
}
// 지나온 칸수 k를 추가로 전달...
void find2(int r, int c, int N, int k)
{
	if (maze[r][c] == 3)
	{
		if (minV > k)
			minV = k;
	}
	else
	{
		maze[r][c] = 1; // 지나간 칸을 표시
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (maze[nr][nc] != 1) // 벽이 아니면
				find2(nr, nc, N, k+1);
		}
		maze[r][c] = 0; // 지나간 칸을 지움
	}
}

int find(int r, int c, int N)
{
	if (maze[r][c] == 3)
	{
		return 1;
	}
	else
	{
		maze[r][c] = 1; // 지나간 칸을 표시
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (maze[nr][nc] != 1) // 벽이 아니면
				if (find(nr, nc, N)) // 이동.. 
					return 1; // 목적지를 찾고 리턴하면 1리턴. 검색 중단.
		}
		return 0; // 현재 경로에서 목적지를 찾지 못함...
	}
}
