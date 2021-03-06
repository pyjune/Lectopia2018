#include <stdio.h>

int adj[11][11]; // 노드가 10번까지 있는 경우..
int visited[11]; // 방문 표시
int V, E; // 1~V번 노드 사용, E개의 간선이 주어지는 경우

// 경로수
int cnt;
void dfs(int n, int k);
// 최단거리
int minV;
void dfs2(int n, int k, int e);
// 경로 저장
int l[11];
int minl[11];

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T;tc++)
	{
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1;
			//adj[n2][n1] = 1;
		}
		minV = E;
		dfs2(0, V, 0);
		printf("#%d %d %d\n", tc, minV, cnt);
		for (int i = 0; i <= minV; i++)
		{
			printf("%d ", minl[i]);
		}
		printf("\n");
		cnt = 0;
		//dfs(0, V);
		//printf("#%d %d\n", tc, cnt);
		for (int i = 0; i <= V; i++)
		{
			visited[i] = 0;
			for (int j = 0; j <= V; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
}
void dfs2(int n, int k, int e)
{
	cnt++;
	if (n == k)
	{
		l[e] = k;
		if (minV > e)
		{
			minV = e;
			for (int i = 0; i <= e; i++)
				minl[i] = l[i];
		}
	}
	else if (e >= minV) // 호출횟수를 줄일 수 있음..
		return;
	else
	{
		visited[n] = 1;
		l[e] = n;
		for (int i = 0; i <= V; i++)
		{
			// i가 인접이고 방문하지 않은 노드면
			if (adj[n][i] == 1 && visited[i] == 0) //
			{
				dfs2(i, k, e+1); // i로 이동..
			}
		}
		visited[n] = 0;
	}
}

void dfs(int n, int k)
{
	if (n == k)
		cnt++;
	else
	{
		visited[n] = 1;

		for (int i = 0; i <= V; i++)
		{
			// i가 인접이고 방문하지 않은 노드면
			if (adj[n][i] == 1 && visited[i] == 0) //
			{
				dfs(i, k); // i로 이동..
			}
		}
		visited[n] = 0;
	}
}
