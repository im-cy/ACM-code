#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int sz = 200100;
queue < int > q;
int hed[sz],nxt[sz],dist[sz];
int dis[sz];
int tot = 1;
int edge[sz],tim[sz];
bool visable[sz],use[sz];
int n;
void build(int f,int t)
{
	edge[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void init()
{
	tot = 1;
	while(!q.empty())
		q.pop();
	memset(use,0,sizeof(use));
	memset(dis,0,sizeof(dis));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(edge,0,sizeof(edge));
	memset(dist,0,sizeof(dist));
	memset(visable,0,sizeof(visable));
	memset(tim,0,sizeof(tim));
	for(int i = 1 ; i <= n ; i ++)
	{
		int m;
		scanf("%d%d",&dist[i],&m);
		for(int j = 1 ; j <= m ; j ++)
		{
			int t;
			scanf("%d",&t);
			build(i,t);
		}
	}
	return ;
}

bool spfa()
{
	for(int i = 1 ; i <= n ; i ++)
		dis[i] = -214748364;
	dis[1] = 100;
	q.push(1);
	use[1] = 1;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		use[f] = 0;
		for(int i = hed[f] ; i ; i = nxt[i])
		{
			int t = edge[i];
			if(dis[f] + dist[t] > 0 && dis[f] + dist[t] > dis[t])
			{
				dis[t] = dis[f] + dist[t];
				tim[t] ++;
				if(tim[t] > n && !visable[t])
				{
					dis[t] = 21474836;
					visable[t] = 1;
					q.push(t);
				}
				if(!visable[t] && !use[t])
				{
					use[t] = 1;
					q.push(t);
				}
			}
		}
	}
	if(dis[n] > 0)
		return true;
	return false;
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		init();
		if(n == -1)
			break;
		if(spfa())
			puts("winnable");
		else
			puts("hopeless");
	}
	return 0;
}

