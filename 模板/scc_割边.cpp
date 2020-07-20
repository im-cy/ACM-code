int low[sz],dfn[sz],dfs_clock;
struct gtnd
{
    int f,t;
}cut[sz];//cut[] 存割边连接的两个点
int conut;
int tarjan(int u,int fa)
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
            if(dfn[u] < low[v])
                cut[++conut].f = u , cut[count].t = v;
        }
        else if(dfn[v] < dfn[u] && v != fa)
            low[u] = min(dfn[v],low[u]);
    }
    return low[u];
}
