#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char A[100][101];

int find(int N, int M);
int find2(int N, int M);

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
		if (r == 0)
			r = find2(N, M);
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
					printf("%c", A[row][i + l]);
				return 1;
			}
		}
	}
	return 0;
}

int find2(int N, int M)
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
				if (A[i+k][row] != A[i + M - 1 - k][row]) // 세로로 검색
					break; // 다르면 중단..
			}
			if (k == M / 2) // for문이 끝까지 돌아갔으면 회문 찾음..
			{
				for (int l = 0; l < M; l++)
					printf("%c", A[i + l][row]); // 세로로 읽은 문자 
				return 1;
			}
		}
	}
	return 0;
}
