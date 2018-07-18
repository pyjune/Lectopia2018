#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find(int K, int N, int M, const int stop[]);

int main(void)
{
	int T;

	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int stop[101] = { 0 }; // 충전기 위치를 1로 표시하기 위한 배열
		int K, N, M;
		scanf("%d %d %d", &K, &N, &M);
		for (int i = 0; i < M; i++)
		{
			int n;
			scanf("%d", &n);
			stop[n] = 1; // n번 정류장에 충전기 표시
		}
		int r = find(K, N, M, stop); // 충전횟수 리턴
		printf("#%d %d\n", tc, r);
	}
}

int find(int K, int N, int M, const int stop[]) //충전횟수 리턴..
{
	int i = 0; // 마지막 충전위치...
	int cnt = 0; // 충전횟수
	while ((i+K) < N) // 종점에 도착전이면 반복
	{
		int j = 0; // 충전소를 찾아 뒤로가는 정류장 수
		while (stop[i + K - j] == 0)
		{
			j++;
			if (j == K) // K만큼 뒤로가야하면 진행 불가
				return 0;
		}
		i = i + K - j; // 마지막 충전위치
		cnt++;
	}
	return cnt;
}
