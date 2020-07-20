#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
int n,m;
const int sz = 2000100;
int hed[sz],nxt[sz],l[sz];
ll w[sz],dist[sz];
int rd[sz],cd[sz];
bool use[sz];
int tot = 1;
queue < int > q;
queue < int > top_q;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
	return ;
}
void init()
{
	while(!q.empty())
		q.pop();
	memset(rd,0,sizeof(rd));
	memset(cd,0,sizeof(cd));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(use,0,sizeof(use));
	memset(dist,0,sizeof(dist));
	memset(w,0,sizeof(w));
	memset(l,0,sizeof(l));
	tot = 1;
	return ;
}

int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		init();
		for(int i = 1 ; i <= n ; i ++)
			scanf("%lld",&w[i]);
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(f,t);
			rd[t] ++;
			cd[f] ++;
		}
		for(int i = 1 ; i <= n ; i ++)
			dist[i] = -2147483647111111111ll;
		for(int i = 1 ; i <= n ; i ++)
			if(rd[i] == 0)
			{
				dist[i] = w[i];
				q.push(i);
			}
		while(!q.empty())
		{
			int f = q.front();
			q.pop();
			for(int i = hed[f] ; i ; i = nxt[i])
			{
				int t = l[i];
				rd[t] --;
				dist[t] = max(dist[t],dist[f] + w[t]);
				if(rd[t] == 0)
				{
					q.push(t);
				}
			}
		}
		ll ans = -2147483647111111111ll;
		for(int i = 1 ; i <= n ; i ++)
			if(cd[i] == 0)
				ans = max(ans,dist[i]);
		printf("%lld\n",ans);
	}
	return 0;
}



