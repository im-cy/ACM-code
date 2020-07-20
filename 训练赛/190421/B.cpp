#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int sz = 1000010;
int hed[sz],nxt[sz];
ll dist[sz],dist_[sz];
queue < int > q;
struct edge
{
	int f,t;
	ll d;
}l[sz],in[sz];
int tot = 1;
bool use[sz];
void build(int f,int t,ll d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int n,m;
void spfa(int s,ll *dist)
{
	for(int i = 1 ; i <= n ; i ++)
		dist[i] = 21474836411111111ll;
	dist[s] = 0;
	use[s] = 1;
	while(!q.empty())
		use[q.front()] = 0 , q.pop();
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
					q.push(t);
					use[t] = 1;
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
		scanf("%d%d%I64d",&in[i].f,&in[i].t,&in[i].d);
		in[i].f ++;
		in[i].t ++;
		build(in[i].f,in[i].t,in[i].d);
		build(in[i].t,in[i].f,in[i].d);
	}
	spfa(1,dist);
	spfa(n,dist_);
	int length = dist[n];
	ll ans = 0;
	for(int i = 1 ; i <= m ; i ++)
	{
		if(dist[in[i].f] + dist_[in[i].t] + in[i].d == length)
			ans += in[i].d;
		else if(dist[in[i].t] + dist_[in[i].f] + in[i].d == length)
			ans += in[i].d;
	}
	ans *= 2;
	printf("%I64d\n",ans);
	return 0;
}

