// 코드배틀27 No.1
#include <stdio.h>

char str[1002];

int find(void);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%s", str);
		int r = find();
		printf("#%d %d\n", tc, r);
	}
}

int find(void)
{
	int a = str[0] - '0'; // 박수치는 사람
	int b = 0; // 부족한 사람

	int i = 1;
	while (str[i] != '\0')
	{
		if (i > a) // 박수치는 사람이 부족하면
		{
			b += i - a; // 보충
			a = i;
		}
		
		a += (str[i]-'0'); // i번에서 박수치는 사람 추가
		i++;
	}
	return b;
}
