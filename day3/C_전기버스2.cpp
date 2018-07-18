#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int find(int K, int N, int M, const int stop[]);
int find2(int K, int N, int M, const int s[]);

int main(void)
{
	int T;

	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		int s[102] = { 0 }; // 시점은 항상 0
		int K, N, M;
		scanf("%d %d %d", &K, &N, &M);
		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &s[i]); // 충전기 위치 저장
		}
		s[M + 1] = N; // 종점 번호 추가
		int r = find2(K, N, M, s); // 충전횟수 리턴

		printf("#%d %d\n", tc, r);

	}
}
int find2(int K, int N, int M, const int s[])
{
	int i = 1; // 현재 인덱스..
	int l = 0; // 마지막 충전 위치
	int cnt = 0;
	while (i<=M+1) // 종점에 도달 전이면
	{
		if ((s[i] - s[i - 1]) > K) // 이전 충전기와의 거리가 최대 이동거리보다 크면
			return 0; // 운행불가
		if ((l + K) < s[i]) // 마지막 충전위치+K보다 현재 위치가 더 멀면
		{
			l = s[i - 1]; // s[i]까지 올 수 없으므로, s[i-1]이 마지막 충전위치가 됨
			cnt++;
		}
		i++;
	}
	return cnt;
}
