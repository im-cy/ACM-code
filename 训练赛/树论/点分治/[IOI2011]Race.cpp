#include <bits/stdc++.h>
using namespace std;
const int sz = 2000100;
const int INF = 2e9;
int n,k;
struct node
{
    int t,d;
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
struct P
{
	int dis,tim;
}dd[sz];
int cnt;
int dist[sz];
void calcdis(int u,int fa,int dep)
{
    dd[++cnt].dis = dist[u];
    dd[cnt].tim = dep;
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        int w = l[u][i].d;
        if(vis[v] || v == fa)
            continue;
        dist[v] = dist[u] + w;
        calcdis(v,u,dep+1);
    }
}
int tf[10000010];
int ans = 214748364;
queue < int > tag;
void dfz(int u)
{
	tf[0] = 0;
	tag.push(0);
    vis[u] = true;
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        int w = l[u][i].d;
        if(vis[v])
            continue;
        dist[v] = w;
        calcdis(v,u,1);
        for(int j = 1 ; j <= cnt ; j ++)
            if(dd[j].dis <= k)
				if(tf[k - dd[j].dis] != -1)
    	        {
        	    	ans = min(ans,tf[k-dd[j].dis] + dd[j].tim);
            	}
        for(int j = 1 ; j <= cnt ; j ++)
        {
            if(tf[dd[j].dis] == -1)
            	tf[dd[j].dis] = dd[j].tim;
            else
            	tf[dd[j].dis] = min(tf[dd[j].dis],dd[j].tim);
            tag.push(dd[j].dis);
        }
        cnt = 0;
    }
    while(!tag.empty())
    {
        tf[tag.front()] = -1;
        tag.pop();
    }
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        int w = l[u][i].d;
        if(vis[v])
            continue;
        sum = size[v];
        root = 0;
        maxx[root] = INF;
        calcsiz(v,u);
        calcsiz(root,-1);
        dfz(root);
    }
}
int main()
{
	for(int i = 0 ; i <= 1000000 ; i ++)
		tf[i] = -1;
    scanf("%d%d",&n,&k);
    for(int i = 1; i < n; i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a ++ , b ++;
        build(a,b,c);
    }
    root = 0;
    maxx[root] = INF;
    sum = n;
    calcsiz(1, -1);
    calcsiz(root, -1);
    dfz(root);
    if(ans == 214748364)
    	puts("-1");
    else
	    printf("%d\n",ans);
    return 0;
}
