#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char bin[16][5] = { "0000", "0001", "0010", "0011",
					"0100", "0101", "0110", "0111",
					"1000", "1001", "1010", "1011",
					"1100", "1101", "1110", "1111" };

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		scanf("%d", &N);
		printf("#%d ", tc);
		for (int x = 0; x < N; x++)
		{
			int num;
			scanf("%1x", &num);
			printf("%s", bin[num]);
			/*
			for (int i = 3; i >= 0; i--)
			{
				if ((num&(1 << i)) == 0)
					printf("0");
				else
					printf("1");
			}
			*/
		}
		printf("\n");
	}
	/*
	int num = 0x4;

	for (int i = 3; i >= 0; i--)
	{
		if ((num&(1 << i)) == 0)
			printf("0");
		else
			printf("1");
	}*/
	/* // 16진수 1자리 변환
	if ((num&(1 << 3)) == 0)
		printf("0");
	else
		printf("1");
	if ((num&(1 << 2)) == 0)
		printf("0");
	else
		printf("1");
	if ((num&(1 << 1)) == 0)
		printf("0");
	else
		printf("1");
	if ((num&(1 << 0)) == 0)
		printf("0");
	else
		printf("1");
		*/
}
