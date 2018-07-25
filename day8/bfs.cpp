// 노드가 최대 10개라면...
#include <stdio.h>

int q[10];
int f = -1; // 마지막으로 디큐한 위치
int r = -1; // 마지막으로 인큐한 위치

// 인접행렬
int adj[11][11];
int visited[11];
int V, E;

void bfs(int n);

int main(void)
{
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		adj[n2][n1] = 1;
	}
	bfs(1);
	printf("\n");
	int s = 0;
	for (int i = 1; i <= V; i++)
		s += visited[i];
	printf("%d\n", s - V);
}

void bfs(int n)
{
	// 초기화
	q[++r] = n; // 시작노드 인큐
	visited[n] = 1;
	// 반복
	while (f != r)
	{
		n = q[++f]; // 디큐
		printf("%d ", n); // visit()
		for (int i = 1; i <= V; i++)
		{
			if (adj[n][i] == 1 && visited[i] == 0)
			{
				q[++r] = i; // n과 인접한 i를 인큐
				visited[i] = visited[n] + 1; // n까지 거리에서 1증가
			}
		}
	}
}
