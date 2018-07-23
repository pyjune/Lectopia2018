#include <stdio.h>

int ch1[1002]; // 1~1001번 노드
int ch2[1002];
int par[1002]; // 자식인덱스, 부모번호 저장
int cnt; // 방문한 노드 수..

void f(int n);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int E, N;
		int p, c;
		scanf("%d %d", &E, &N);
		for (int i = 0; i < E; i++)
		{
			//int p, c;
			scanf("%d %d", &p, &c);
			// 부모를 인덱스로 자식번호 저장..
			if (ch1[p] == 0)
				ch1[p] = c;
			else
				ch2[p] = c;
			// 자식을 인덱스로 부모번호 저장..
			par[c] = p;
		}
		// 조상..
		int anc = 0;
		c = N;
		while (par[c] != 0) // 부모가 있으면
		{
			c = par[c];
			anc++;
		}
		// 자손의 수..
		cnt = 0; // 방문한 노드 수
		f(N);
		printf("#%d %d %d\n", tc, anc, cnt - 1);
		for (int i = 1; i <= E + 1; i++) // 배열 초기화...
		{
			ch1[i] = 0;
			ch2[i] = 0;
			par[i] = 0;
		}
	}

}

void f(int n)
{
	if (n > 0)
	{
		cnt++;
		f(ch1[n]);
		f(ch2[n]);
	}
}
