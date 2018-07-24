#include <stdio.h>

int adj[11][11]; // 노드가 10번까지 있는 경우..
void dfs(int n);
int visited[11]; // 방문 표시
int V, E; // 1~V번 노드 사용, E개의 간선이 주어지는 경우
int main(void)
{
	freopen("Text.txt", "r", stdin);
	
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1;
	}
	dfs(1);
}

void dfs(int n)
{
	visited[n] = 1;
	printf("%d ", n);
	for (int i = 1; i <= V; i++)
	{
		// i가 인접이고 방문하지 않은 노드면
		if (adj[n][i] == 1 && visited[i] == 0) //
		{
			dfs(i); // i로 이동..
		}
	}
}
