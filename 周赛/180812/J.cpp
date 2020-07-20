#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int size = 200010;
int head[size],next[size];
int par[size][32],deep[size];
int tot = 1,l[size];
int cf[size];
void build(int f,int t)
{
    l[tot] = t;
    next[tot] = head[f];
    head[f] = tot ++;
}
int n,m;
void dfs(int u,int fa,int dep)
{
    par[u][0] = fa;
    deep[u] = dep;
    for(int i = head[u] ; i ; i = next[i])
    {
        int v = l[i];
        if(v != fa)
            dfs(v,u,dep+1);
    }
}
int lca(int u,int v)
{
    int ans = 0;
    if(deep[u] < deep[v])
        swap(u,v);
    for(int i = 31 ; i >= 0 ; i --)
        if(deep[par[u][i]] >= deep[v])
            u = par[u][i];
    for(int i = 31 ; i >= 0 ; i --)
        if(par[u][i] != par[v][i])
            u = par[u][i] , v = par[v][i];
    if(u != v)
        u = par[u][0] , v = par[v][0];
    return u;
}
void dfs_ans(int u,int fa)
{
	for(int i = head[u] ; i ; i = next[i])
	{
		int v = l[i];
		if(v != fa)
		{
			dfs_ans(v,u);
			cf[u] += cf[v];
		}
	}
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i < n ; i ++)
    {
        int f,t;
        scanf("%d%d",&f,&t);
        build(f,t);
        build(t,f);
    }
    dfs(1,0,1);
    for(int i = 1 ; i <= 31 ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            par[j][i] = par[par[j][i-1]][i-1];
    for(int i = 1 ; i <= m ; i ++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        cf[u] ++;
        cf[v] ++;
        cf[lca(u,v)] -= 2;
    }
    dfs_ans(1,0);
    int ans = 0;
    for(int i = 2 ; i <= n ; i ++)
    {
    	if(cf[i] == 1)
    		ans ++;
    	else if(cf[i] == 0)
    		ans += m;
    }
    printf("%d\n",ans);
    return 0;
}
