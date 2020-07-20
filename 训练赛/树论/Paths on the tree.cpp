#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz];//dist[i][j]记录了第 i 个节点向上走 2^j 步走的边的权值和 
int par[sz][32],deep[sz];//par[i][j]记录了第 i 个节点向上走 2^j 步可以到达的节点，deep记录了深度 
int tot = 1;//边的数量 
int l[sz];
int n,m;
bool vis[sz];
struct node
{
	int u,v,lcauv;
}ins[sz];
void init()
{
	memset(ins,0,sizeof(ins));
	memset(vis,0,sizeof(vis));
	memset(l,0,sizeof(l));
	memset(par,0,sizeof(par));
	memset(deep,0,sizeof(deep));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	tot = 1;
}
bool cmp(node a,node b)
{
	return deep[a.lcauv] > deep[b.lcauv];
}
void build(int f,int t) // 建一条 f点到 t 点权值为 d 的有向边 
{
    l[tot] = t;
    nxt[tot] = hed[f];
    hed[f] = tot ++;
}
void dfs(int u,int fa,int dep)//预处理深度、每个节点的父亲节点、边权 
{
    par[u][0] = fa;
    deep[u] = dep;
    for(int i = hed[u] ; i ; i = nxt[i])
    {
        int v = l[i];
        if(v != fa)
            dfs(v,u,dep+1);
    }
}
int lca(int u,int v)//求树上 u v 两点的距离 
{
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
    return u; // 此时,若 u v 两点联通(即树不是森林) u == v ，且此时的 u v 为询问时 u v 的最近公共祖先 
}
void dfs1(int u)
{
	vis[u] = 1;
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i];
		if(vis[v] || deep[v] < deep[u])
			continue;
		dfs1(v);
	}
}
//n个点的树，给定m条路径，选出尽可能多的路径且路径间不能有重叠 
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
    	init();
    	for(int i = 1 ; i < n ; i ++)//点编号从 1 开始
	    {
	        int f,t;
	        scanf("%d%d",&f,&t);
	        build(f,t);
	        build(t,f);//建边 
	    }
	    dfs(1,0,1);//预处理 
	    for(int i = 1 ; i <= 31 ; i ++)
	        for(int j = 1 ; j <= n ; j ++)
	            par[j][i] = par[par[j][i-1]][i-1];//倍增思想
	    for(int i = 1 ; i <= m ; i ++)
	    {
	    	scanf("%d%d",&ins[i].u,&ins[i].v);
	    	ins[i].lcauv = lca(ins[i].u,ins[i].v);
	    }
	    sort(ins+1,ins+m+1,cmp);
	    int ans = 0;
	    for(int i = 1 ; i <= m ; i ++)
	    {
	    	if(vis[ins[i].u] || vis[ins[i].v])
	    		continue;
	    	ans ++;
	    	dfs1(ins[i].lcauv);
	    }
	    printf("%d\n",ans);
    }
    return 0;
}
