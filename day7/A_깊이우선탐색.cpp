#include <stdio.h>

int adj[11][11]; // 노드가 10번까지 있는 경우..
void dfs(int n);
int visited[11]; // 방문 표시
int V, E; // 1~V번 노드 사용, E개의 간선이 주어지는 경우

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
		printf("#%d", tc);
		dfs(0);
		printf("\n");
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

void dfs(int n)
{
	visited[n] = 1;
	printf(" %d", n);
	for (int i = 0; i <= V; i++)
	{
		// i가 인접이고 방문하지 않은 노드면
		if (adj[n][i] == 1 && visited[i] == 0) //
		{
			dfs(i); // i로 이동..
		}
	}
}
