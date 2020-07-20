#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int sz = 200010;
int head[sz],nxt[sz],l[sz];
int tot = 1;
int n,m;
void build(int f,int t)
{
    l[tot] = t;
    nxt[tot] = head[f];
    head[f] = tot ++;
}
int low[sz],dfn[sz],dfs_clock;
bool is_cut[sz];//第 i 点是否为割点 
int tarjan(int u,int fa)//当前节点 u 和他的上一个节点 fa 
{
    dfn[u] = low[u] = ++ dfs_clock;
    int child = 0;
    for(int i = head[u] ; i ; i = nxt[i])
    {
        int v = l[i];
        if(!dfn[v])
        {
            child ++;
            low[v] = tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if(dfn[u] <= low[v])
                is_cut[u] = 1;// 
        }
        else if(dfn[v] < dfn[u] && v != fa)
            low[u] = min(dfn[v],low[u]);
    }
    if(child == 1 && fa == 0)
        is_cut[u] = 0;
    return low[u];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= m ; i ++)
    {
        int f,t;
        scanf("%d%d",&f,&t);
        build(f,t);
        build(t,f);
    }
    for(int i = 1 ; i <= n ; i ++)
        if(!dfn[i])
            tarjan(i,0);//防止图不连通 
    return 0;
}
