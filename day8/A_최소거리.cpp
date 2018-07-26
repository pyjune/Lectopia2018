#include <stdio.h>

int adj[11][11]; // 노드가 10번까지 있는 경우..
int visited[11]; // 방문 표시
int V, E; // 1~V번 노드 사용, E개의 간선이 주어지는 경우

int q[11];
int f;
int r;

// 최단거리
int bfs(int n, int V);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1;
			//adj[n2][n1] = 1;
		}
		f = -1; // 큐의 인덱스 초기화
		r = -1;
		int r = bfs(0, V);
		printf("#%d %d\n", tc, r);
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

int bfs(int n, int V)
{
	q[++r] = n; // 인큐
	visited[n] = 1;
	while (f != r)
	{
		n = q[++f]; // 디큐
		if (n == V) // 마지막 노드에 도착하면
			return visited[V] - 1;
		for (int i = 0; i <= V; i++)
		{
			if (adj[n][i] == 1 && visited[i] == 0)
			{
				q[++r] = i;
				visited[i] = visited[n] + 1;
			}
		}
	}
}
