#include <stdio.h>

int find1(int n);
int find2(int n);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		printf("#%d %d\n", tc, find2(N));

	}
}

int find2(int n)
{
	int d[2][31] = { 0 };
	d[0][1] = 0; // 1비트일 때 0인 경우의 수
	d[1][1] = 1; // 1비트일 때 1인 경우의 수
	for (int i = 2; i <= n; i++)
	{
		d[0][i] = d[1][i - 1]; // 앞자리가 무조건 1
		d[1][i] = d[0][i - 1] + d[1][i - 1];
	}
	return d[0][n] + d[1][n];
}
int find1(int n)
{
	int cnt = 0;
	// 1로 시작하는 n자리 이진수 i..
	for (int i = (1 << (n - 1)); i < (1 << n); i++)
	{
		int j;
		for (j = 1; j < n - 1; j++)
		{
			if (((i&(1 << (j - 1))) == 0) && ((i&(1 << j)) == 0))
				break;
		}
		if (j == n - 1)
			cnt++;
	}
	return cnt;
}
