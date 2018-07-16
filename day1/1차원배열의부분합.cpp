#include <stdio.h>

int main(void) 
{
	
	int tc, T;
	int i,j;
	int N, M;
	int sum;
	int min, max;
	//freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		int A[100];
		scanf("%d %d", &N, &M);
		for(i=0;i<N;i++)
		{
			scanf("%d", &A[i]);
		}
		min = 0x7fffffff;
		max = 0;
   
		for(i=0;i<=N-M;i++)
		{
			sum = 0;			
			for(j=0;j<M;j++)
			{
				sum += A[i+j];
			}
			if(min>sum)
				min = sum;
			if(max<sum)
				max = sum;
			
		}
		
		
		printf("#%d %d\n", tc, max-min);
	}
	
	return 0;
}
