#include <stdio.h>

int adj[11][11]; // 노드가 10번까지 있는 경우..
void dfs(int n);
int visited[11]; // 방문 표시
int V, E; // 1~V번 노드 사용, E개의 간선이 주어지는 경우

int stack[11];
int top = -1;

int main(void)
{
	freopen("Text.txt", "r", stdin);
	
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 무향그래프인 경우 적용
	}
	dfs(1);
}

void dfs(int n) // 반복구조 dfs
{
	// 초기화 : 모든 인접노드 push()
	visited[n] = 1;
	printf("%d ", n);
	for (int i = 1; i <= V; i++)
	{
		if (adj[n][i] == 1)
		{
			stack[++top] = i;
			visited[i] = 1;
		}
	}
	// 스택이 비어있지 않으면 반복
	while (top != -1)
	{
		n = stack[top--];

		visited[n] = 1;
		printf("%d ", n);
		for (int i = 1; i <= V; i++)
		{
			if (adj[n][i] == 1 && visited[i] == 0)
			{
				stack[++top] = i;
				visited[i] = 1; // push+visited
			}
		}

	}
}
