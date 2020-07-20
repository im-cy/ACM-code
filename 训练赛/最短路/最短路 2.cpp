#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int sz = 200100*4;
const ll mod = 998244353998244353;
struct node
{
	int p;
	ll d;
	int pr;
	bool operator < (const node & x) const
	{
		return x.d < d;
	}
};
priority_queue < node > q; // slf
int n,m;
ll dist[1010];
int pre[1010];
struct edge
{
    int t;
	ll d;
};
vector < edge > l[1010];
bool use[1010];
void build(int f,int t,ll d)
{
    l[f].push_back({t,d});
    l[t].push_back({f,d});
}
void spfa(int s)
{
    for(int i = 1 ; i <= n ; i ++)
        dist[i] = (ll)1e18 , pre[i] = (ll)1e9;
    dist[s] = 0;
    pre[s] = 0;
    q.push({s,0,0});
    while(!q.empty())
    {
        node f = q.top();
        q.pop();
        if(dist[f.p] < f.d)
        	continue;
        for(int i = 0 ; i < l[f.p].size() ; i ++)
        {
            int t = l[f.p][i].t;
            ll d = l[f.p][i].d;
            if(dist[t] > dist[f.p] + d)
            {
                dist[t] = dist[f.p] + d;
                pre[t] = f.pr;
                q.push({t,dist[t],max(f.pr,t)});
            }
            else if(dist[t] == dist[f.p] + d)
            {
            	pre[t] = min(pre[t],f.pr);
            	q.push({t,dist[t],max(f.pr,t)});
            }
        }
    }
}
int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
int main()
{
	int T = read();
	while(T --)
	{
		while(!q.empty())
			q.pop();
		n = read() , m = read();
		for(int i = 1 ; i <= n ; i ++)
			l[i].clear();
		for(int i = 1 ; i <= m ; i ++)
		{
			int f = read() , t = read() , d = read();
			build(f,t,d);
		}
		ll ans = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			spfa(i);
			for(int j = 1 ; j <= n ; j ++)
				ans += pre[j] % mod , ans %= mod;
		}
		printf("%I64d\n",ans);
	}
    return 0;
}
