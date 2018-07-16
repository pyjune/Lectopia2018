#include <stdio.h>

int strLen(char s[]);

int main(void)
{
	int tcase, T;
	int i, j;
	int N, M;

	char p[101];
	char t[1001];

	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (tcase = 1; tcase <= T; tcase++)
	{
		scanf("%s", p);
		scanf("%s", t);
		N = strLen(p);
		M = strLen(t);

		printf("#%d", tcase);
		for (i = 0; i <= M - N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (p[j] != t[i + j])
					break;
			}
			if (j == N)
				break;
		}
		if (j == N)
		{
			printf(" 1\n");
		}
		else
		{
			printf(" 0\n");
		}
	}

}

int strLen(char s[])
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}
