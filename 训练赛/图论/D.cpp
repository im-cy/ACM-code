#include <cstdio>
#include <cstring>
#define MAXN 517
int G[MAXN][MAXN];
int in_degree[MAXN];
int ans[MAXN];
int n, m, x, y;
int i, j;
 
void toposort()
{
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(G[i][j])
			{
				in_degree[j]++;
			}
		}
	}
	for(i = 1; i <= n; i++)
	{
		int k = 1;
		while(in_degree[k] != 0)
			k++;
		ans[i] = k;
		in_degree[k] = -1;
		for(int j = 1; j <= n; j++)
		{
			if(G[k][j])
				in_degree[j]--;
		}
	}
}
 
void init()
{
	memset(in_degree,0,sizeof(in_degree));
	memset(ans,0,sizeof(ans));
	memset(G,0,sizeof(G));
}
 
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		init();
		for(i = 0; i < m; i++)
		{
			scanf("%d%d",&x,&y);
			G[x][y] = 1;
		}
		toposort();
		for(i = 1; i < n; i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[n]);
	}
	return 0;
}
