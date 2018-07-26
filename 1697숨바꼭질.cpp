#include <stdio.h>
int v[100001];
int q[100001];
int f=-1;
int r=-1;
int bfs(int n,int m);

int main(void)
{
	int n,m;
	scanf("%d %d", &n,&m);
    printf("%d" , bfs(n,m));
}
int bfs(int n,int m)
{
	q[++r] =n;
	v[n]=1;
	while(f!=r)
	{
		int t=q[++f];
		if(t==m)
		    return v[t]-1;
		if(t>0&&v[t-1]==0)
		{
			q[++r]=t-1;
			v[t-1]=v[t]+1;
		}
		if(t<100000&&v[t+1]==0)
		{
			q[++r]=t+1;
			v[t+1]=v[t]+1;
		}
		if(2*t<=100000&&v[2*t]==0)
		{
			q[++r]=t*2;
			v[t*2]=v[t]+1;
		}
	}
}
