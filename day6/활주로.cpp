#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[20][20];

int find(int N, int X);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, X;
		scanf("%d %d", &N, &X);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		int r = find(N, X);
		printf("#%d %d\n", tc, r);
	}
}

int find(int N, int X)
{
	int cnt = 0; // 건설 가능한 경우의 수
	int code[20] = { 0 };
	int len[20] = { 0 };
	for (int r = 0; r < N; r++)
	{
		int i = 0;
		len[0] = 1;
		code[0] = map[r][0];
		for (int c = 1; c < N; c++) // run-length
		{
			if (map[r][c] == code[i])
			{
				len[i]++;
			}
			else
			{
				i++;
				code[i] = map[r][c];
				len[i] = 1;
			}
		}
		// 마지막 코드, i인덱스 까지
		if (len[0] == N)
			cnt++; // 전체가 같으므로 가능
		else
		{
			int j;
			for (j = 1; j <= i; j++)
			{
				if (code[j] - code[j - 1] > 1 || code[j] - code[j - 1] < -1)
					break; // 2이상 차이가 나므로 건설 불가
				else if (code[j] - code[j - 1] == 1 && len[j - 1] >= X) // 높이 1증가, 이전 길이가 X이상이면 경사로 설치
					len[j - 1] -= X;
				else if (code[j] - code[j - 1] == -1 && len[j] >= X) // 1감소하고, 이후 길이가 X이상이면 경사로 설치
					len[j] -= X;
				else
					break;
			}
			if (j == i + 1)
				cnt++;
		}
		i = 0;
		len[0] = 1;
		code[0] = map[0][r];
		for (int c = 1; c < N; c++) // run-length
		{
			if (map[c][r] == code[i])
			{
				len[i]++;
			}
			else
			{
				i++;
				code[i] = map[c][r];
				len[i] = 1;
			}
		}
		// 마지막 코드, i인덱스 까지
		if (len[0] == N)
			cnt++; // 전체가 같으므로 가능
		else
		{
			int j;
			for (j = 1; j <= i; j++)
			{
				if (code[j] - code[j - 1] > 1 || code[j] - code[j - 1] < -1)
					break; // 2이상 차이가 나므로 건설 불가
				else if (code[j] - code[j - 1] == 1 && len[j - 1] >= X) // 높이 1증가, 이전 길이가 X미만이면 불가
					len[j - 1] -= X;
				else if (code[j] - code[j - 1] == -1 && len[j] >= X) // 1감소하고, 이후 길이가 X미만이면 불가
					len[j] -= X;
				else
					break;
			}
			if (j == i + 1)
				cnt++;
		}
	}
	return cnt;
}

