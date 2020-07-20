#include<bits/stdc++.h>
using namespace std;
const int sz = 1050;
int n,m;
int num[sz][sz];
int rnum[sz][sz],rmax[sz];
int cnum[sz][sz],cmax[sz];
int tmp[sz];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			scanf("%d",&num[i][j]);
		}
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			tmp[j] = num[i][j];
		}
		sort(tmp+1,tmp+m+1);
		int cnt = unique(tmp+1,tmp+m+1) - (tmp+1);
		for(int j = 1 ; j <= m ; j ++)
			rnum[i][j] = lower_bound(tmp+1,tmp+cnt+1,num[i][j]) - (tmp);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		int maxn = 0;
		for(int j = 1 ; j <= m ; j ++)
		{
			maxn = max(maxn,rnum[i][j]);
		}
		rmax[i] = maxn;
	}
	
	for(int i = 1 ; i <= m ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
		{
			tmp[j] = num[j][i];
		}
		sort(tmp+1,tmp+n+1);
		int cnt = unique(tmp+1,tmp+n+1) - (tmp+1);
		for(int j = 1 ; j <= n ; j ++)
			cnum[j][i] = lower_bound(tmp+1,tmp+cnt+1,num[j][i]) - (tmp);
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		int maxn = 0;
		for(int j = 1 ; j <= n ; j ++)
		{
			maxn = max(maxn,cnum[j][i]);
		}
		cmax[i] = maxn;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			printf("%d ",max(rnum[i][j],cnum[i][j]) + max(cmax[j]-cnum[i][j],rmax[i]-rnum[i][j]));
			
		}
		puts("");
	}
	return 0;
}

