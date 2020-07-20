#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int sz = 200100*4;
struct node
{
	int p,d;
	bool operator < (const node & x) const
	{
		return x.d < d;
	}
};
priority_queue < node > q; // slf
int n,m,c;
int head[sz],nxt[sz],dist[sz];
int lay[sz];
bool vis[sz];
struct edge
{
    int t,d;
}l[sz];
int tot = 1;
bool use[sz];
void build(int f,int t,int d)
{
    l[tot].t = t;
    l[tot].d = d;
    nxt[tot] = head[f];
    head[f] = tot ++;
}
int spfa(int s,int e)
{
	memset(use,0,sizeof(use));
    for(int i = 1 ; i <= 2*n ; i ++)
        dist[i] = 2147483641;
    dist[s] = 0;
    node st;
    st.p = s;
    st.d = 0;
    q.push({s,0});
    while(!q.empty())
    {
        node f = q.top();
        q.pop();
        if(use[f.p])
        	continue;
        use[f.p] = 1;
        for(int i = head[f.p] ; i ; i = nxt[i])
        {
            int t = l[i].t;
            if(use[t])
            	continue;
            if(dist[t] > dist[f.p] + l[i].d)
            {
                dist[t] = dist[f.p] + l[i].d;
                q.push({t,dist[t]});
            }
        }
    }
    if(dist[e] == 2147483641)
    	return -1;
    return dist[e];
}
int main()
{
	int T;
	int Case = 0;
	scanf("%d",&T);
	while(T --)
	{
		Case ++;
		memset(vis,0,sizeof(vis));
		memset(l,0,sizeof(l));
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		while(!q.empty())
			q.pop();
		tot = 0;
		scanf("%d%d%d",&n,&m,&c);
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%d",&lay[i]);
			vis[lay[i]] = 1;
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			build(n+lay[i],i,0);
			if(lay[i] == 1 && vis[lay[i]+1])
			{
				build(i,n+lay[i]+1,c);
			}
			else if(lay[i] == n && vis[lay[i]-1])
			{
				build(i,n+lay[i]-1,c);
			}
			else
			{
				if(vis[lay[i]-1])
				{
					build(i,n+lay[i]-1,c);
				}
				if(vis[lay[i]+1])
				{
					build(i,n+lay[i]+1,c);
				}
			}
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t,d;
			scanf("%d%d%d",&f,&t,&d);
			build(f,t,d);
			build(t,f,d);
		}
		printf("Case #%d: %d\n",Case,spfa(1,n));
	}
    return 0;
}
