#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


long long f(int n);

int main(void)
{
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		long long r = f(N);
		printf("#%d %lld\n", tc, r);
	}
}

long long f(int n)
{
	if (n < 2) // f(0)=1, f(1)=1
		return 1;
	else if (n == 2)   // f(2)=3
		return 3;
	else             // n이 3이상인 경우
		return f(n - 1) + 2 * f(n - 2) + f(n - 3);
}
