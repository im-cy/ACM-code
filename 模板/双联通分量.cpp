int root, cnt;
int vis[maxn], dfn[maxn], low[maxn];
bool cut[maxn];
//vector<pair<int, int>>bridge;

void dfs(int u, int fa)
{
    int son=0;
    vis[u]=1;
    dfn[u]=low[u]=++cnt;
    for (int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if (v==fa) continue;
        if (vis[v]==1) low[u]=min(low[u], dfn[v]); //·µ×æ±ß
        if (vis[v]==0)
        {
            dfs(v, u);
            son++;
            low[u]=min(low[u], low[v]);
            if ( (u==root && son>1) || (u!=root && low[v]>=dfn[u]))
            {
                cut[u]=true;
                //if(low[v] > dfn[u]) bridge.push_back({u, v}); //(u, v) ÊÇÇÅ
            }
        }
    }
    vis[u]=2;
}

void tarjan_init()
{
    memset(vis, 0, sizeof(vis));
    memset(cut, 0, sizeof(cut));
    cnt=0; root=1;
    //bridge.clear();
}
