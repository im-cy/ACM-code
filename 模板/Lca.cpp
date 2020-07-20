#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int size = 200010;
int head[size],next[size],dist[size][32];//dist[i][j]记录了第 i 个节点向上走 2^j 步走的边的权值和 
int par[size][32],deep[size];//par[i][j]记录了第 i 个节点向上走 2^j 步可以到达的节点，deep记录了深度 
int tot = 1;//边的数量 
struct dc
{
    int t,d;
}l[size];
void build(int f,int t,int d) // 建一条 f点到 t 点权值为 d 的有向边 
{
    l[tot].t = t;
    l[tot].d = d;
    next[tot] = head[f];
    head[f] = tot ++;
}
int n;
void dfs(int u,int fa,int dep,int dis)//预处理深度、每个节点的父亲节点、边权 
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
int lca(int u,int v)//求树上 u v 两点的距离 
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
    return ans; // 此时,若 u v 两点联通(即树不是森林) u == v ，且此时的 u v 为询问时 u v 的最近公共祖先 
}
int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i < n ; i ++)//点编号从 1 开始
    {
        int f,t,d;
        scanf("%d%d%d",&f,&t,&d);
        build(f,t,d);
        build(t,f,d);//建边 
    }
    dfs(1,0,1,0);//预处理 
    for(int i = 1 ; i <= 31 ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            par[j][i] = par[par[j][i-1]][i-1] , dist[j][i] = dist[j][i-1] + dist[par[j][i-1]][i-1];//倍增思想 
    int m;
    scanf("%d",&m);
    for(int i = 1 ; i <= m ; i ++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",lca(u,v));
    }
    return 0;
}
