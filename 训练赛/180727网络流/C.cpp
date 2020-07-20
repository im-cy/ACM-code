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
int n,m,s,t,F,D;
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
{/*
	1 - 100 food 
	101 - 200 cow_l 
	201 - 300 cow_r 
	301 - 400 drink 
	s 401 t 402
*/
	init();
	n = read_int() , F = read_int() , D = read_int() , s = 401 , t = 402;
	for(int i = 1 ; i <= F ; i ++)
		build(s,i,1) , build(i,s,0);
	for(int i = 1 ; i <= D ; i ++)
		build(i+300,t,1) , build(t,i+300,0);
	for(int i = 1 ; i <= n ; i ++)
		build(i+100,i+200,1) , build(i+200,i+100,0);
	for(int i = 1 ; i <= n ; i ++)
	{
		int fi = read_int() , di = read_int();
		for(int j = 1 ; j <= fi ; j ++)
		{
			int cowi_food = read_int();
			build(cowi_food,i+100,1);
			build(i+100,cowi_food,0);
		}
		for(int j = 1 ; j <= di ; j ++)
		{
			int cowi_drink = read_int();
			build(i+200,cowi_drink+300,1);
			build(cowi_drink+300,i+200,0);
		}
	}
	n = 402;
	printf("%lld\n",Dinic());
	return 0;
}
 
