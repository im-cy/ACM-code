#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int size = 2000010;
int head[size],nxt[size],dist[size];
struct dc
{
	int t,d;
}l[size];
int tot = 1;
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = head[f];
	head[f] = tot ++;
}
int n,m;
queue < int > q;
int	ti[size];
bool use[size];
bool spfa()
{
	for(int i = 0 ; i <= n ; i ++)
		dist[i] = 214748364;
	q.push(0);
	use[0] = 1;
	dist[0] = 0;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		use[f] = 0;
		for(int i = head[f] ; i ; i = nxt[i])
		{
			int t = l[i].t;
			if(dist[t] > dist[f] + l[i].d)
			{
				dist[t] = dist[f] + l[i].d;
				ti[t] = ti[f] + 1;
				if(ti[t] > n)
					return false;
				if(!use[t])
				{
					use[t] = 1;
					q.push(t);
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int f,t,d;
		scanf("%d%d%d",&f,&t,&d);
		build(t,f,d);
	}
	for(int i = 1 ; i <= n ; i ++)
		build(0,i,0);
//建图部分根据题目来 
	int minn = 2147483641;
	bool flag = spfa();
	for(int i = 1 ; i <= n ; i ++)
		minn = min(minn,dist[i]);
	for(int i = 1 ; i <= n ; i ++)
		if(dist[i] == 214748364)
			dist[i] = 0;
	if(minn < 0)
		for(int i = 1 ; i <= n ; i ++)
			dist[i] += -minn;
	else
		for(int i = 1 ; i <= n ; i ++)
			dist[i] -= minn;
	if(flag)
		for(int i = 1 ; i <= n ; i ++)
			printf("%d\n",dist[i]);
	else
		puts("NO SOLUTION");
	return 0;
}
/*
5 8
1 2 0
1 5 -1
2 5 1
3 1 5
4 1 4
4 3 -1
5 3 -1
5 4 -3
*/
