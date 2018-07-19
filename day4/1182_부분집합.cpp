#include <stdio.h>

int L[20];
int A[20];
int cnt;
void f(int n, int k, int x);

int main(void)
{

	int N, X;
	scanf("%d %d", &N, &X);
	for (int i = 0; i<N; i++)
		scanf("%d", &A[i]);
	cnt = 0;
	f(0, N, X);
	printf("%d\n", cnt);

}

void f(int n, int k, int x)
{
	if (n == k)
	{
		int s = 0;
		for (int i = 0; i < k; i++) // 공집합인지 확인
			s += L[i];
		if (s != 0) // 공집합이 아닌경우
		{
			s = 0;
			for (int i = 0; i < k; i++)
				if (L[i] == 1)
					s += A[i];
			//printf("%d ", i + 1); // 부분집합을 출력하는 경우
			//printf("\n");
			if (s == x)
				cnt++;
		}
	}
	else
	{
		L[n] = 0;
		f(n + 1, k, x);
		L[n] = 1;
		f(n + 1, k, x);
	}
}
