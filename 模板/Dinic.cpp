#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long 
using namespace std;
const int sz = 200010;
const ll inf = 21474836471111ll;
queue < int > q;
int head[sz],next[sz],edge[sz];
ll w[sz];
int dep[sz],cur[sz];
int tot;
int n,m,s,t;
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
	memset(next,-1,sizeof(next));
	return ;
}
void build(int f,int t,ll d)
{
	edge[tot] = t;
	w[tot] = d;
	next[tot] = head[f];
	head[f] = tot ++;
	return ;
}
void build_edge(int f,int t,ll d)
{
	build(f,t,d);
	build(t,f,0);
}
ll dfs(int u,ll dist)
{
	if(u == t)
		return dist;
	for(int &i = cur[u] ; i != -1 ; i = next[i])
	{
		if((dep[edge[i]] == dep[u] + 1) && w[i])
		{
			ll di = dfs(edge[i],min(dist,w[i]));
			if(di > 0)
			{
				w[i] -= di;
				w[i^1] += di;
				return di;
			}
		}
	}
	return 0;
}
bool bfs()
{
	while(!q.empty())
		q.pop();
	memset(dep,0,sizeof(dep));
	dep[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		for(int i = head[f] ; i != -1 ; i = next[i])
		{
			if((w[i] > 0) && !dep[edge[i]])
			{
				dep[edge[i]] = dep[f] + 1;
				if(edge[i] == t)
					return true;
				q.push(edge[i]);
			}
		}
	}
	return dep[t];
}
ll Dinic()
{
	ll ans = 0;
	while(bfs())
	{
		for(int i = 1 ; i <= n ; i ++)
			cur[i] = head[i];
		while(int d = dfs(s,inf))
			ans += d;
	}
	return ans;
}
int read_int()
{
	int x = 0 , f = 1;
	char ins = getchar();
	while(ins < '0' || ins > '9')
	{
		if(ins == '-')
			f = -1;
		ins = getchar();
	}
	while(ins >= '0' && ins <= '9')
	{
		x = (x << 3) + (x << 1) + ins - '0';
		ins = getchar();
	}
	if(f == -1)
		x = -x;
	return x;
}
int read_l()
{
	ll x = 0;
	int f = 1;
	char ins = getchar();
	while(ins < '0' || ins > '9')
	{
		if(ins == '-')
			f = -1;
		ins = getchar();
	}
	while(ins >= '0' && ins <= '9')
	{
		x = x * 10 + ins - '0';
		ins = getchar();
	}
	if(f == -1)
		x = -x;
	return x;
}
int main()
{
	init();
	n = read_int() , m = read_int() , s = read_int() , t = read_int();
	for(int i = 1 ; i <= m ; i ++)
	{
		int f = read_int() , t = read_int();
		ll d = read_l();
		build_edge(f,t,d);
	}
	printf("%lld\n",Dinic());
	return 0;
}
 
