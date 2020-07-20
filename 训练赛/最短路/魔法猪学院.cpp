#include<bits/stdc++.h>
//#include<ext/pb_ds/priority_queue.hpp>
//using namespace __gnu_pbds;
//__gnu_pbds::priority_queue<int>q;//因为放置和std重复，故需要带上命名空间
using namespace std;
const int sz = 200010;
const int INF = 2147483647;
int n,m,tot,cnt,ans,len;
double V;
struct node
{
	int t;
	double d;
}l[sz],ld[sz];

struct Node
{
	int id;
	double g,f;
	bool operator < (const Node &a) const
	{
		return a.f < f;
	}
};
int hed[5010],Hed[5010],nxt[sz],Nxt[sz];
bool vis[5010];
double dis[5010];
priority_queue<Node>Q;
queue < int > q;
void build(int f,int t,double d)
{
	l[++tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot;
	ld[++cnt].t = f;
	ld[cnt].d = d;
	Nxt[cnt] = Hed[t];
	Hed[t] = cnt;
}
void spfa()
{
	for(int i = 1 ; i <= n ; i ++)
		dis[i] = INF;
	q.push(1);
	dis[1] = 0;
	vis[1] = 0;
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		vis[f] = 0;
		for(int i = hed[f] ; i ; i = nxt[i])
		{
			int t = l[i].t;
			if(dis[t] > dis[f] + l[i].d)
			{
				dis[t] = dis[f] + l[i].d;
				if(!vis[t])
				{
					vis[t] = 1;
					q.push(t);
				}
			}
		}
	}
}
void Astar()
{
	if(dis[n] == INF)
		return ;
	Node tmp;
	tmp.id = n , tmp.g = 0 , tmp.f = dis[n];
	Q.push(tmp);
	while(!Q.empty())
	{
		Node u = Q.top();
		Q.pop();
		if(u.id == 1)
		{
			V -= u.g;
			if(V >= 0)
				ans ++;
			else
				return ;
		}
		for(int i = Hed[u.id] ; i ; i = Nxt[i])
		{
			int t = ld[i].t;
			tmp.g = u.g + ld[i].d;
			tmp.f = tmp.g + dis[t];
			tmp.id = t;
			Q.push(tmp);
		}
	}
}

int main()
{
	int u,v;
	double z;
	scanf("%d%d",&n,&m);
	scanf("%lf",&V);
	for(int i = 1 ; i <= m ; i ++)
	{
		int f,t;
		double d;
		scanf("%d%d%lf",&f,&t,&d);
		build(f,t,d);
	}
	spfa();
	Astar();
	printf("%d\n",ans);
	return 0;
}





