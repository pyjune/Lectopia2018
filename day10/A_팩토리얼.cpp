#include <stdio.h>

long long f[21];

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N, D;
		scanf("%d %d", &N, &D);
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i <= N; i++)
			f[i] = i*f[i - 1] % D;
		printf("#%d %lld\n", tc, f[N]);
	}
}
