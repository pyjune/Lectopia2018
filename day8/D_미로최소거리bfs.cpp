#include <stdio.h>

int maze[100][100];

int find(int r, int c, int N);
int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

typedef struct{
	int r;
	int c;
}PosType;
PosType q[10000];
int front;
int rear;
int visited[100][100];

int bfs(int sr, int sc);

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
				visited[i][j] = 0;
				scanf("%1d", &maze[i][j]);
				if (maze[i][j] == 2) // 시작 좌표 찾기
				{
					sr = i;
					sc = j;
				}
			}
		}
		front = -1;
		rear = -1;
		int r = bfs(sr, sc);
		printf("#%d %d\n", tc, r);
	}
}

int bfs(int sr, int sc)
{
	rear++;
	q[rear].r = sr;
	q[rear].c = sc; // 시작점 enq
	visited[sr][sc] = 1;
	while (front != rear)
	{
		PosType t = q[++front];
		/*
		++front;
		int tr = q[front].r;
		int tc = q[front].c;
		*/
		if (maze[t.r][t.c] == 3)
			return visited[t.r][t.c]-2;
		// 인접이고(벽이 아니고) 방문안한 i에 대해...
		for (int i = 0; i < 4; i++)
		{
			int nr = t.r + dr[i];
			int nc = t.c + dc[i];
			if (maze[nr][nc] != 1 && visited[nr][nc] == 0)
			{
				++rear;
				q[rear].r = nr;
				q[rear].c = nc;
				visited[nr][nc] = visited[t.r][t.c] + 1;
			}
		}
	}
	return 0;
}
