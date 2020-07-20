#include<bits/stdc++.h>
using namespace std;
const int sz = 200010;
struct edge
{
	int t,d;
};
vector < edge > l[sz];
void build(int f,int t)
{
	l[f].push_back({t,1});
	l[t].push_back({f,-1});
}
int n,m;
bool vis[sz];
int dist[sz];
int ans1;
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
void dfs(int u)
{
	vis[u] = 1;
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i].t;
		int w = l[u][i].d;
		if(vis[v])
			ans1 = gcd(ans1,abs(dist[u] - dist[v] + w));
		else
		{
			dist[v] = dist[u] + w;
			dfs(v);
		}
	}
}
int maxn,minn;
void getlen(int u)
{
	vis[u] = 1;
	minn = min(minn,dist[u]);
	maxn = max(maxn,dist[u]);
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i].t;
		int w = l[u][i].d;
		if(!vis[v])
		{
			dist[v] = dist[u] + w;
			getlen(v);
		}
	}
}
void solve()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		if(!vis[i])
			dfs(i);
	}
	if(ans1)
	{
		if(ans1 < 3)
		{
			puts("-1 -1");
			return ;
		}
		for(int i = 3 ; i <= ans1 ; i ++)
		{
			if(ans1 % i == 0)
			{
				printf("%d %d\n",ans1,i);
				return ;
			}
		}
	}
	for(int i = 1 ; i <= n ; i ++)
		vis[i] = 0 , dist[i] = 0;
	int ans2 = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(!vis[i])
		{
			maxn = 0;
			minn = 0;
			getlen(i);
			ans2 += maxn - minn + 1;
		}
	}
	if(ans2 < 3)
	{
		puts("-1 -1");
		return ;
	}
	printf("%d 3\n",ans2);
	return ;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		build(f,t);
	}
	solve();
	return 0;
}

