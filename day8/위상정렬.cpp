#include <stdio.h>

int V, E;
int adj[11][11]; // 인접행렬
int ind[11]; // 진입차수
int coin[11];

int q[100];
int f = -1;
int r = -1;
int maxV;

void tsort(void);

int main(void)
{
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		ind[n2]++; // 진입차수 (도착으로 언급된 횟수 기록)
	}
	maxV = 0;
	tsort();
	printf("\n%d\n", maxV);
}

void tsort(void)
{
	for (int i = 1; i <= V; i++)
	{
		if (ind[i] == 0) // i번 노드의 진입차수가 0이면
		{
			q[++r] = i; // 인큐
			coin[i] = 1;
		}
	}
	while (f != r)
	{
		int t = q[++f]; // 디큐
		printf("%d ", t);
		for (int i = 1; i <= V; i++)
		{
			if (adj[t][i] == 1)
			{
				ind[i]--; // 인접인 노드의 진입차수 1감소
				if (ind[i] == 0)
				{
					q[++r] = i; // 진입차수가 0이면 인큐
					coin[i] = coin[t] + 1;
					if (maxV < coin[i]) // 최대 동전개수를 찾는 다면..
						maxV = coin[i];
				}
			}
		}
	}
}
