#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define INF 1e9+7
using namespace std;
const int sz = 200010;
struct edge
{
	int t,d;
}l[sz];
int hed[sz],nxt[sz],dp[sz][3];
int pre[sz];
int tot = 1;
void init()
{
	tot = 1;
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(dp,0,sizeof(dp));
	memset(pre,0,sizeof(pre));
}
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int n;
void dfs1(int u,int fa)
{
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i].t;
		int w = l[i].d;
		if(v == fa)
			continue;
		dfs1(v,u);
		if(dp[u][0] < dp[v][0] + w)
		{
			dp[u][0] = dp[v][0] + w;
			pre[u] = v;
		}
	}
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i].t;
		int w = l[i].d;
		if(v == fa)
			continue;
		if(v == pre[u])
			continue;
		dfs1(v,u);
		dp[u][1] = max(dp[v][0] + w,dp[u][1]);
		
	}
}
void dfs2(int u,int fa)
{
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i].t;
		int w = l[i].d;
		if(v == fa)
			continue;
		if(v == pre[u])
			dp[v][2] = max(dp[u][1],dp[u][2]) + w;
		else
			dp[v][2] = max(dp[u][0],dp[u][2]) + w;
		dfs2(v,u);
	}
}
int main()
{
	while(scanf("%d",&n) != EOF)
	{
		init();
		for(int i = 2 ; i <= n ; i ++)
		{
			int t,d;
			scanf("%d%d",&t,&d);
			build(i,t,d);
			build(t,i,d);
			
		}
		dfs1(1,-1);
		dfs2(1,-1);
		for(int i = 1 ; i <= n ; i ++)
			printf("%d\n",max(dp[i][0],dp[i][2]));
	}
	
	return 0;
}

