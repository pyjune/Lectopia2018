#include <stdio.h>

int A[] = { 10, 20, 30 };
int B[3];

void f(int n, int k);
long long fact(int n);

int main(void)
{
	//f(0, sizeof(A)/sizeof(A[0])); // f(0, 3);
	printf("%lld\n", fact(14));
}

long long fact(int n)
{
	if (n < 2)
		return 1;
	else
		return n * fact(n - 1);
}
void f(int n, int k) // n 현재 인덱스, k 배열의 크기
{
	if (n == k) // 인덱스가 크기와 같아진 경우
	{
		for (int i = 0; i < k; i++)
			printf("%d ", B[i]);
		return;
	}
	else // 유효한 인덱스 범위인 경우
	{
		B[n] = A[n];
		f(n + 1, k); // 다음 인덱스로 이동
	}
}
