#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T;

	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		int cnt[10] = { 0 };
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int num;
			scanf("%1d", &num);
			cnt[num]++;		// 숫자의 개수를 기록..
		}
		/*
		int a[100];
		for (int i = 0; i < N; i++)
		{
			int num;
			scanf("%1d", &a[i]);
			
		}
		for (int i = 0; i < N; i++)
		{
			cnt[a[i]]++;
		}
		*/
		// 최대값의 인덱스 찾기
		int maxIdx = 0;
		for (int i = 1; i < 10; i++)
		{
			if (cnt[i] >= cnt[maxIdx])
				maxIdx = i;
		}
		printf("#%d %d %d\n", tc, maxIdx, cnt[maxIdx]);
	}

}
