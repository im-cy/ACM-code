#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int sz = 2000010;
int hed[sz],nxt[sz],dist[sz],dis[sz];
int tot = 1;
struct Edge
{
	int f,t,d;
}l[sz],edge[sz];
queue < int > q;
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int n,m;
bool use[sz];
void spfa(int s)
{
	for(int i = 1 ; i <= n ; i ++)
		dist[i] = 214748364;
	dist[s] = 0;
	use[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		use[f] = 0;
		for(int i = hed[f] ; i ; i = nxt[i])
		{
			int t = l[i].t;
			if(dist[t] > dist[f] + l[i].d)
			{
				dist[t] = dist[f] + l[i].d;
				if(!use[t])
				{
					use[t] = 1;
					q.push(t);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		u ++ , v ++;
		edge[i].f = u , edge[i].t = v , edge[i].d = d;
		build(u,v,d);
		build(v,u,d);
	}
	spfa(1);
	for(int i = 1 ; i <= n ; i ++)
		dis[i] = dist[i];
	spfa(n);
	int ans = 0;
	for(int i = 1 ; i <= m ; i ++)
	{
		int u=edge[i].f , v = edge[i].t , d = edge[i].d;
		if(dis[u] + dist[v] + d == dis[n] || dist[u] + dis[v] + d == dis[n])
			ans += d;
	}
	printf("%d\n",ans*2);
	return 0;
}

