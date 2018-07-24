#include <stdio.h>

int adj[11][11]; // 노드가 10번까지 있는 경우..
int visited[11]; // 방문 표시
int V, E; // 1~V번 노드 사용, E개의 간선이 주어지는 경우

int cnt;
void dfs(int n, int k); // n출발,  k 도착

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
	dfs(1, 4); // 1에서 4로가는 경로의 개수 찾기
	printf("%d\n", cnt);
}

void dfs(int n, int k) 
{
	if (n == k)
		cnt++;
	else
	{
		visited[n] = 1;
		for (int i = 1; i <= V; i++)
		{
			if (adj[n][i] == 1 && visited[i] == 0)
			{
				dfs(i, k);
			}
		}
		visited[n] = 0; // 다른경로로 n에 진입하는 것을 허용
	}
}
