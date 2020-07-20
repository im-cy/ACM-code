#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 201000;
int hed[sz],nxt[sz],dist[sz][32];//dist[i][j]记录了第 i 个节点向上走 2^j 步走的边的权值和 
int par[sz][32],deep[sz];//par[i][j]记录了第 i 个节点向上走 2^j 步可以到达的节点，deep记录了深度 
int tot = 1;//边的数量 
struct edge
{
    int f,t,d;
    bool pick;
}l[sz],g[sz];
bool cmp(edge a,edge b)
{
	return a.d < b.d;
}
void build(int f,int t,int d) // 建一条 f点到 t 点权值为 d 的有向边 
{
    l[tot].t = t;
    l[tot].d = d;
    nxt[tot] = hed[f];
    hed[f] = tot ++;
}
int n;
void dfs(int u,int fa,int dep,int dis)//预处理深度、每个节点的父亲节点、边权 
{
    par[u][0] = fa;
    dist[u][0] = dis;
    deep[u] = dep;
    for(int i = hed[u] ; i ; i = nxt[i])
    {
        int v = l[i].t;
        if(v != fa)
            dfs(v,u,dep+1,l[i].d);
    }
}
int lca(int u,int v)//求树上 u v 两点的距离 
{
    int ans = 0;
    if(deep[u] < deep[v])
        swap(u,v);
    for(int i = 31 ; i >= 0 ; i --)
        if(deep[par[u][i]] >= deep[v])
            ans = max(dist[u][i],ans) , u = par[u][i];
    for(int i = 31 ; i >= 0 ; i --)
        if(par[u][i] != par[v][i])
            ans = max(dist[u][i],max(dist[v][i],ans)) , u = par[u][i] , v = par[v][i];
    if(u != v)
        ans = max(dist[u][0],max(dist[v][0],ans)) , u = par[u][0] , v = par[v][0];
    return ans; // 此时,若 u v 两点联通(即树不是森林) u == v ，且此时的 u v 为询问时 u v 的最近公共祖先 
}
int f[sz];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
void init()
{
	memset(l,0,sizeof(l));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	tot = 1;
}
int main()
{
	int T,n,m;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i = 1 ; i <= n ; i ++)
			f[i] = i;
		for(int i = 1 ; i <= m ; i ++)
		{
			scanf("%d%d%d",&g[i].f,&g[i].t,&g[i].d);
			g[i].pick = 0;
		}
		sort(g+1,g+m+1,cmp);
		int mst = 0;
		for(int i = 1 ; i <= m ; i ++)
		{
			int ff = find(g[i].f);
			int tt = find(g[i].t);
			if(ff != tt)
			{
				build(g[i].f,g[i].t,g[i].d);
				build(g[i].t,g[i].f,g[i].d);
				g[i].pick = 1;
				f[tt] = ff;
				mst += g[i].d;
			}
		}
	    dfs(1,0,1,0);//预处理 
	    for(int i = 1 ; i <= 31 ; i ++)
	        for(int j = 1 ; j <= n ; j ++)
	            par[j][i] = par[par[j][i-1]][i-1] , dist[j][i] = max(dist[j][i-1],dist[par[j][i-1]][i-1]);//倍增思想 
		bool is_unique = 1;
		for(int i = 1 ; i <= m ; i ++)
		{
			if(g[i].pick)
				continue;
			int dis = lca(g[i].f,g[i].t);
//			printf("dis %d\n",dis);
			if(dis == g[i].d)
			{
				is_unique = 0;
				break;
			}
		}
		if(is_unique)
		{
			printf("%d\n",mst);
		}
		else
		{
			puts("Not Unique!");
		}
	}
	return 0;
}
 
