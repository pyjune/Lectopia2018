#include <stdio.h>

int arr[100];

int main(void)
{
	int T;
	scanf("%d", &T);
	
	for (int tc = 1; tc <= T; tc++)
	{
		// 입력
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		// 오름차순정렬
		for (int i = 0; i <= N - 2; i++) // 정렬 구간의 맨앞
		{
			int minIdx = i;
			for (int j = i + 1; j <= N - 1; j++) // 비교 구간
			{
				if (arr[j] < arr[minIdx])
					minIdx = j;
			}
			int temp = arr[minIdx]; // 가장 작은 값은 구간 맨 앞으로..
			arr[minIdx] = arr[i];
			arr[i] = temp;
		}
		// 10개 출력
		printf("#%d", tc);
		for (int i = 0; i < 5; i++)
		{
			printf(" %d %d", arr[N - 1-i], arr[i]);
		}
		printf("\n");

	}

}
