#define _CRT_SECURE_NO_WARNINGS //Visual Studio인 경우에만
#include <stdio.h>
int arr[1000];

int main(void)
{
	int T; // 테스트케이스 개수..

	freopen("Text.txt", "r", stdin); // 제출시 주석처리
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		//int a[] = { 0 };
		int N;

		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}
		// 최대 최소값 찾기
		int minV = arr[0];
		int maxV = arr[0];

		for (int i = 1; i < N; i++)
		{
			if (maxV < arr[i])
				maxV = arr[i];
			if (minV > arr[i])
				minV = arr[i];
		}
		printf("#%d %d\n", tc, maxV - minV);
	}

}
