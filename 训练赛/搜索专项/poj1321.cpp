#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,k;
bool vis[11];
char mp[11][11];
int ans;
void dfs(int i,int k)
{
	if(k == 0)
	{
		ans ++;
		return ;
	}
	if(i > n)
		return ;
	for(int j = 1 ; j <= n ; j ++)
	{
		if(mp[i][j] == '#' && !vis[j])
		{
			vis[j] = 1;
			dfs(i+1,k-1);
			vis[j] = 0;
		}
	}
	dfs(i+1,k);
}
int main()
{
	while(scanf("%d%d",&n,&k) && n != -1)
	{
		ans = 0;
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= n ; j ++)
			{
				char in = getchar();
				while(in != '#' && in != '.')
					in = getchar();
				mp[i][j] = in;
			}
		dfs(1,k);
		printf("%d\n",ans);
	}
	
	return 0;
}

