#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 20010;
const int INF = 2e9;
int n,m;
struct node
{
    int t;
	int d;
};
vector <node> l[sz];
int q[sz];
int root,maxx[sz],size[sz],sum;
bool vis[sz];
void build(int f,int t,int d)
{
    l[f].push_back({t,d});
    l[t].push_back({f,d});
}
void calcsiz(int u,int fa)
{
    size[u] = 1;
    maxx[u] = 0;
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        int w = l[u][i].d;
        if(v == fa || vis[v])
            continue;
        calcsiz(v,u);
        maxx[u] = max(maxx[u],size[v]);
        size[u] += size[v];
    }
    maxx[u] = max(maxx[u],sum-size[u]);
    if(maxx[u] < maxx[root])
        root = u;
}
int dd[sz],cnt;
int dist[sz];
void calcdis(int u,int fa)
{
    dd[++cnt] = dist[u];
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        ll w = l[u][i].d;
        if(vis[v] || v == fa)
            continue;
        dist[v] = dist[u] + w;
        calcdis(v,u);
    }
}
bool tf[10000010];
int ans[sz];
queue < int > tag;
void dfz(int u,int fa)
{
    tf[0] = true;
    tag.push(0);
    vis[u] = true;
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        int w = l[u][i].d;
        if(vis[v] || v == fa)
            continue;
        dist[v] = w;
        calcdis(v,u);
        for(int j = 1 ; j <= cnt ; j ++)
            for(int k = 1 ; k <= m ; k ++)
                if(q[k] >= dd[j])
                    ans[k] |= tf[q[k] - dd[j]];
        for(int j = 1 ; j <= cnt ; j ++)
        {
            tf[dd[j]] = true;
            tag.push(dd[j]);
        }
        cnt = 0;
    }
    while(!tag.empty())
    {
        tf[tag.front()] = false;
        tag.pop();
    }
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        int w = l[u][i].d;
        if(vis[v] || v == fa)
            continue;
        sum = size[v];
        root = 0;
        maxx[root] = INF;
        calcsiz(v,u);
        calcsiz(root,-1);
        dfz(root,u);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        build(a,b,c);
    }
    for (int i = 1; i <= m; i++)
        scanf("%d", &q[i]);
    root = 0;
    maxx[root] = INF;
    sum = n;
    calcsiz(1, -1);
    calcsiz(root, -1);
    dfz(root, -1);
    for(int i = 1; i <= m; i++)
    {
    	if(q[i] == 0)
    	{
    		puts("Yes");
    		continue;
    	}
    	if(ans[i])
            printf("Yes\n");
        else
            printf("No\n");
    	
    }
    return 0;
}
