#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
const int sz = 200100;
const int INF = 2e9;
int n,k;
struct node
{
    int t,d;
}l[sz];
int hed[sz],nxt[sz];
int tot = 1;
int root,maxx[sz],size[sz],sum;
bool vis[sz];
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void calcsiz(int u,int fa)
{
    size[u] = 1;
    maxx[u] = 0;
    for(int i = hed[u] ; i ; i = nxt[i])
    {
        int v = l[i].t;
        int w = l[i].d;
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
ll dis[11];
ll dist[sz];
void calcdis(int u,int fa)
{
    dis[dist[u]%3] ++;
    for(int i = hed[u] ; i ; i = nxt[i])
    {
        int v = l[i].t;
        int w = l[i].d % 3;
        if(vis[v] || v == fa)
            continue;
        dist[v] = (dist[u] + w) % 3;
        calcdis(v,u);
    }
}
ll solve(int u,int d,int fa)
{
	dis[0] = 0 , dis[1] = 0, dis[2] = 0;
	dist[u] = d % 3;
	calcdis(u,fa);
	ll anss = dis[1] * dis[2] * 2ll + dis[0] * dis[0];
/*	int i = 1 , j = cnt;
	while(i < j)
	{
		while(i < j && dd[i] + dd[j] > k)
			j --;
		anss += j - i;
		i ++;
	}*/
	return anss;
}
ll ans;
void dfz(int u,int fa)
{
    ans += solve(u,0,fa);
    vis[u] = true;
    for(int i = hed[u] ; i ; i = nxt[i])
	{
        int v = l[i].t;
        int w = l[i].d;
        if(vis[v])
            continue;
        ans -= solve(v,w,u);
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
	memset(hed,0,sizeof(hed));
	memset(vis,0,sizeof(vis));
	ans = 0 , tot = 1;
}
ll gcd(ll a,ll b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main()
{
    scanf("%d",&n);
    {
    	for(int i = 1; i < n; i++)
	    {
	        int a,b,c;
	        scanf("%d%d%d", &a, &b, &c);
	        build(a,b,c%3);
	        build(b,a,c%3);
	    }
	    root = 0;
	    maxx[root] = INF;
	    sum = n;
	    calcsiz(1, -1);
	    calcsiz(root, -1);
	    dfz(root, -1);
	    ll gcd_ = gcd(ans,1ll*n*n);
	    printf("%lld/%lld\n", ans/gcd_,n*n/gcd_);
    	init();
    }
    return 0;
}
