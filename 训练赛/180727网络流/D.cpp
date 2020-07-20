#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long 
using namespace std;
const int sz = 200010;
const int inf = 214748364;
queue < int > q;
int head[sz],next[sz],edge[sz];
int w[sz];
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
void build(int f,int t,int d)
{
	edge[tot] = t;
	w[tot] = d;
	next[tot] = head[f];
	head[f] = tot ++;
	return ;
}
void build_edge(int f,int t,int d)
{
	build(f,t,d);
	build(t,f,0);
}
int dfs(int u,int dist)
{
	if(u == t)
		return dist;
	for(int &i = cur[u] ; i != -1 ; i = next[i])
	{
		if((dep[edge[i]] == dep[u] + 1) && w[i])
		{
			int di = dfs(edge[i],min(dist,w[i]));
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
int Dinic()
{
	int ans = 0;
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
int main()
{
	init();
	n = read_int() , m = read_int();
	s = n + 1 , t = n + 2;
	for(int i = 1 ; i <= n ; i ++)
	{
		int ai = read_int();
		int bi = read_int();
		build_edge(s,i,ai);
		build_edge(i,t,bi);
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		int f = read_int() , t = read_int() , wi = read_int();
		build_edge(f,t,wi);
		build_edge(t,f,wi);
	}
	n = t;
	printf("%d\n",Dinic());
	return 0;
}
 
