#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int size = 200010;
int head[size],next[size],dist[size][32];//dist[i][j]��¼�˵� i ���ڵ������� 2^j ���ߵıߵ�Ȩֵ�� 
int par[size][32],deep[size];//par[i][j]��¼�˵� i ���ڵ������� 2^j �����Ե���Ľڵ㣬deep��¼����� 
int tot = 1;//�ߵ����� 
struct dc
{
    int t,d;
}l[size];
void build(int f,int t,int d) // ��һ�� f�㵽 t ��ȨֵΪ d ������� 
{
    l[tot].t = t;
    l[tot].d = d;
    next[tot] = head[f];
    head[f] = tot ++;
}
int n;
void dfs(int u,int fa,int dep,int dis)//Ԥ������ȡ�ÿ���ڵ�ĸ��׽ڵ㡢��Ȩ 
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
int lca(int u,int v)//������ u v ����ľ��� 
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
    return ans; // ��ʱ,�� u v ������ͨ(��������ɭ��) u == v ���Ҵ�ʱ�� u v Ϊѯ��ʱ u v ������������� 
}
int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i < n ; i ++)//���Ŵ� 1 ��ʼ
    {
        int f,t,d;
        scanf("%d%d%d",&f,&t,&d);
        build(f,t,d);
        build(t,f,d);//���� 
    }
    dfs(1,0,1,0);//Ԥ���� 
    for(int i = 1 ; i <= 31 ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            par[j][i] = par[par[j][i-1]][i-1] , dist[j][i] = dist[j][i-1] + dist[par[j][i-1]][i-1];//����˼�� 
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
