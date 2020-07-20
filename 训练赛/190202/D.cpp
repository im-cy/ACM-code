#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int sz = 2000100;
int hed[sz],nxt[sz];
ll dist[sz];
int tot = 1;
int n,m;
struct edge
{
	int t;
	ll d;
}l[sz];
void build(int f,int t,ll d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int pre[sz];
queue < int > q;
bool use[sz],vis[sz];
int ans[sz];
bool is_find;
void spfa(int start)
{
	while(!q.empty())
		q.pop();
	for(int i = 1 ; i <= n ; i ++)
		dist[i] = 214748364111ll;
	dist[start] = 0;
	use[start] = 1;
	q.push(start);
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
				pre[t] = f;
				if(!use[t])
				{
					use[t] = 1;
					q.push(t);
				}
			}
		}
	}
}
void dfs(int p)
{
	if(p == 2)
	{
		is_find = 1;
		printf("%d ",ans[0]+1);
		for(int i = 1 ; i <= ans[0] ; i ++)
		{
			printf("%d ",ans[i]-1);
		}
		puts("1");
	}
	for(int i = hed[p] ; i ; i = nxt[i])
	{
		int t = l[i].t;
		if(!vis[t] && pre[p] != t)
		{
			vis[t] = 1;
			ans[++ans[0]] = p;
			dfs(t);
			ans[ans[0]--] = 0;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int f,t;
		ll d;
		scanf("%d%d%I64d",&f,&t,&d);
		f ++;
		t ++;
		build(f,t,d);
		build(t,f,d);
	}
	spfa(2);
	vis[1] = 1;
	dfs(1);
	if(!is_find)
		puts("impossible");
	return 0;
}


