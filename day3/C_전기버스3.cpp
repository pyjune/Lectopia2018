#include <stdio.h>

int K;
int N;

int a[101];

int find(void);
int main(void)
{
	int T;
	int M;
	int tmp;
	int r;
	freopen("Text1.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d %d", &K, &N, &M);
		for (int i = 0; i <= N; i++)
			a[i] = 0;
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &tmp);
			a[tmp] = 1;
		}
		// 처리부분...
		r = find();
		printf("#%d %d\n", tc, r);
		// 
	}
}
int find(void)
{
	int cnt = 0;
	int i = 0;
	int j;
	j = i + K;
	while (j < N)
	{
		// j에 충전기가 있는 경우
		if (a[j] == 1)
		{
			i = j;
			j = j + K;
			cnt++;
		}
		else // j에 충전기가 없는 경우
		{
			while (j > i)
			{
				j--;
				if (j == i)
					return 0;
				else if (a[j] == 1)
				{
					//i = j;
					//j = j + K;
					//cnt++;
					break;
				}
			}
			
		}

	}
	return cnt;
}
