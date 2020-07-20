#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
	ll x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
		in = getchar();
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
const int sz = 20010;
const int INF = 2e9;
int n,m;
struct node
{
    int t;
	int d;
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
struct edge
{
	int dis,tim;
}dd[sz];
int cnt;
int dist[sz],len[sz];
void calcdis(int u,int fa)
{
    dd[++cnt].dis = dist[u];
    dd[cnt].tim = len[u];
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i].t;
        ll w = l[u][i].d;
        if(vis[v] || v == fa)
            continue;
        dist[v] = dist[u] + w;
        len[v] = len[u] + 1;
        calcdis(v,u);
    }
}
int num[sz],tf[sz];
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
        len[v] = 1;
        calcdis(v,u);
        for(int j = 1 ; j <= cnt ; j ++)
        {
        	num[dd[j].tim] = max(num[dd[j].tim],dd[j].dis);
        	for(int k = 1 ; k < n ; k ++)
        		if(tf[k])
        			num[k+dd[j].tim] = max(num[k+dd[j].tim],dd[j].dis+tf[k]);
        }
        for(int j = 1 ; j <= cnt ; j ++)
        {
            tf[dd[j].tim] = max(tf[dd[j].tim],dd[j].dis);
            tag.push(dd[j].tim);
        }
        cnt = 0;
    }
    while(!tag.empty())
    {
        tf[tag.front()] = 0;
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
	int T = read();
	while(T --) 
    {
    	scanf("%d%d", &n, &m);
	    for(int i = 1 ; i <= n + 5 ; i ++)
	    	l[i].clear() , num[i] = 0 , vis[i] = 0;
		for (int i = 1; i < n; i++)
	    {
	        int a,b,c;
	        scanf("%d%d%d", &a, &b, &c);
	        build(a,b,c);
	    }
	    
	    root = 0;
	    maxx[root] = INF;
	    sum = n;
	    calcsiz(1, -1);
	    calcsiz(root, -1);
	    dfz(root, -1);
	    for(int i = 1 ; i < n ; i ++)
	    	printf("# %d\n",num[i]);
    }
    return 0;
}
/*
2
3 3
1 2 1
1 3 5
5 6
1 2 100
2 3 5
2 4 1
4 5 1

*/
