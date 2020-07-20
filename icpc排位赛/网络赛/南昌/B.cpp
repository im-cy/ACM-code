#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int sz = 5010;
struct node
{
	int p;
	ll d;
	bool operator < (const node & x) const
	{
		return x.d < d;
	}
};
priority_queue < node > q;
int n,m,s,k,c;
ll dist[sz];
bool vis[sz];
struct edge
{
    int t;
	ll d;
};
vector < edge > l[sz];
void build(int f,int t,ll d)
{
    l[f].push_back({t,d});
}
void dij(int s)
{
    for(int i = 0 ; i <= n ; i ++)
        dist[i] = (ll)1e10 , vis[i] = 0;
    dist[s] = 0;
    q.push({s,0});
    while(!q.empty())
    {
        node f = q.top();
        q.pop();
        if(dist[f.p] < f.d)
        	continue;
        if(vis[f.p])
        	continue;
        vis[f.p] = 1;
        for(int i = 0 ; i < l[f.p].size() ; i ++)
        {
            int t = l[f.p][i].t;
            ll d = l[f.p][i].d;
            if(dist[t] > dist[f.p] + d)
            {
                dist[t] = dist[f.p] + d;
                q.push({t,dist[t]});
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
int team[sz];
int main()
{
	int T = read();
	while(T --)
	{
		n = read() , m = read() , s = read() , k = read() , c = read();
		for(int i = 0 ; i <= n ; i ++)
			l[i].clear();
		for(int i = 1 ; i <= k ; i ++)
			team[i] = read();
		for(int i = 1 ; i <= m ; i ++)
		{
			int f = read() , t = read() , d = read();
			build(f,t,d);
		//	build(t,f,d);
		}
		dij(s);
		ll ans1 = 0;
		for(int i = 1 ; i <= n ; i ++)
			ans1 = max(ans1,dist[i]);
		for(int i = 1 ; i <= k ; i ++)
			build(0,team[i],0);
		dij(0);
		ll ans2 = 0;
		for(int i = 1 ; i <= n ; i ++)
			ans2 = max(ans2,dist[i]);
		if(ans1 <= ans2 * c)
			cout << ans1 << endl;
		else
			cout << ans2 << endl;
	}
    return 0;
}
