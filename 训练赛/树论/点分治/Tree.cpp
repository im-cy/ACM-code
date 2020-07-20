#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int sz = 20010;
const int INF = 2e9;
int n,k;
struct node
{
    int t,d;
};
vector <node> l[sz];
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
        int w = l[u][i].d;
        if(vis[v] || v == fa)
            continue;
        dist[v] = dist[u] + w;
        calcdis(v,u);
    }
}
int solve(int u,int d,int fa)
{
	cnt = 0;
	dist[u] = d;
	calcdis(u,fa);
	sort(dd+1,dd+cnt+1);
	int anss = 0 , i = 1 , j = cnt;
	while(i < j)
	{
		while(i < j && dd[i] + dd[j] > k)
			j --;
		anss += j - i;
		i ++;
	}
	return anss;
}
int ans;
void dfz(int u,int fa)
{
    vis[u] = true;
    ans += solve(u,0,fa);
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        int w = l[u][i].d;
        if(vis[v] || v == fa)
            continue;
        ans -= solve(v,w,fa);
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
void init()
{
	for(int i = 1 ; i <= n ; i ++)
		l[i].clear();
	memset(vis,0,sizeof(vis));
	ans = 0;
}
int main()
{
    while(scanf("%d%d",&n,&k) && n && k)
    {
    	for(int i = 1; i < n; i++)
	    {
	        int a,b,c;
	        scanf("%d%d%d", &a, &b, &c);
	        build(a, b, c);
	    }
	    root = 0;
	    maxx[root] = INF;
	    sum = n;
	    calcsiz(1, -1);
	    calcsiz(root, -1);
	    dfz(root, -1);
	    printf("%d\n", ans);
    	init();
    }
    return 0;
}
