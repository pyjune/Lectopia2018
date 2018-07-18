#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char A[100][101];

int find(int N, int M);

int main(void)
{
	int T;

	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++)
		{
			scanf("%s", A[i]);
		}
		// 
		printf("#%d ", tc);
		int r = find(N, M);
		printf("\n");
		//printf("#%d %d\n", tc, r);
		// printf("#%d %d\n", tc, find(N, M));
	}
}

int find(int N, int M)
{
	for (int row = 0; row < N; row++)
	{
		// 각 줄의 첫 글자 인덱스
		for (int i = 0; i <= N - M; i++)
		{
			// 비교구간
			int k;
			for (k = 0; k < M / 2; k++)
			{
				if (A[row][i + k] != A[row][i + M - 1 - k])
					break; // 다르면 중단..
			}
			if (k == M / 2) // for문이 끝까지 돌아갔으면 회문 찾음..
			{
				for (int l = 0; l < M; l++)
					printf("%c", A[row][i + l]); // 비교 구간의 시작부터 M글자 
				return 1;
			}
		}
	}
	return 0;
}
