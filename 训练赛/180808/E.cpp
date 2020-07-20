#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int size = 100010;
int head[size],next[size],dist[size][32];
int par[size][32],deep[size];
int tot = 1;
struct dc
{
    int t,d;
}l[size];
void init()
{
	tot = 1;
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(dist,0,sizeof(dist));
	memset(par,0,sizeof(par));
	memset(deep,0,sizeof(deep));
	memset(l,0,sizeof(l));
}
void build(int f,int t,int d)
{
    l[tot].t = t;
    l[tot].d = d;
    next[tot] = head[f];
    head[f] = tot ++;
}
int n;
void dfs(int u,int fa,int dep,int dis)
{
    par[u][0] = fa;
    dist[u][0] = dis;
    deep[u] = dep;
    for(int i = head[u] ; i ; i = next[i])
    {
        int v = l[i].t;
        if(v != fa)
            dfs(v,u,dep+1,l[i].d);
    }
}
int lca(int u,int v)
{
    int ans = 0;
    if(deep[u] < deep[v])
        swap(u,v);
    for(int i = 31 ; i >= 0 ; i --)
        if(deep[par[u][i]] >= deep[v])
            ans += dist[u][i] , u = par[u][i];
    for(int i = 31 ; i >= 0 ; i --)
        if(par[u][i] != par[v][i])
            ans += dist[u][i] + dist[v][i] , u = par[u][i] , v = par[v][i];
    if(u != v)
        ans += dist[u][0] + dist[v][0] , u = par[u][0] , v = par[v][0];
    return ans;
}
int main()
{
	init();
	scanf("%d",&n);
    for(int i = 1 ; i < n ; i ++)
   	{
        int f,t,d;
   	    scanf("%d%d%d",&f,&t,&d);
        f ++ , t ++;
        build(f,t,d);
       	build(t,f,d);
    }
	dfs(1,0,1,0);
	for(int i = 1 ; i <= 31 ; i ++)
       	for(int j = 1 ; j <= n ; j ++)
       	    par[j][i] = par[par[j][i-1]][i-1] , dist[j][i] = dist[j][i-1] + dist[par[j][i-1]][i-1];
	int m;
	scanf("%d",&m);
	for(int i = 1 ; i <= m ; i ++)
	{
   		int a,b,c;
   		scanf("%d%d%d",&a,&b,&c);
   		printf("%d\n",(lca(a+1,b+1) + lca(b+1,c+1) + lca(a+1,c+1))/2);
	}
    while(scanf("%d",&n) != EOF)
    {
		puts("");
    	init();
    	for(int i = 1 ; i < n ; i ++)
   		{
    	    int f,t,d;
    	    scanf("%d%d%d",&f,&t,&d);
    	    f ++ , t ++;
    	    build(f,t,d);
       		build(t,f,d);
    	}
		dfs(1,0,1,0);
		for(int i = 1 ; i <= 31 ; i ++)
        	for(int j = 1 ; j <= n ; j ++)
        	    par[j][i] = par[par[j][i-1]][i-1] , dist[j][i] = dist[j][i-1] + dist[par[j][i-1]][i-1];
		int m;
		scanf("%d",&m);
		for(int i = 1 ; i <= m ; i ++)
		{
    		int a,b,c;
    		scanf("%d%d%d",&a,&b,&c);
    		printf("%d\n",(lca(a+1,b+1) + lca(b+1,c+1) + lca(a+1,c+1))/2);
		}
    }
    return 0;
}
