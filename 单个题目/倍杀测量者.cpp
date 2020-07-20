#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
const int sz = 20010;
struct edge
{
	int t;
	double d;
};
vector < edge > l[sz];
int mp[sz];
struct node
{
	int o,f,t,d;
}in[sz];
void build(int f,int t,double d)
{
	l[f].push_back({t,d});
}
int n,m,w;
int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
		in = getchar();
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
double dist[sz];
int tim[sz];
queue < int > q;
bool use[sz];
bool spfa(int s)
{
	for(int i = 0 ; i <= n + 5 ; i ++)
		dist[i] = 214748364.0;
	dist[s] = 0;
	use[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		use[f] = 0;
		for(int i = 0 ; i < l[f].size() ; i ++)
		{
			int t = l[f][i].t;
			double d = l[f][i].d;
			if(dist[t] > dist[f] + d)
			{
				dist[t] = dist[f] + d;
				tim[t] = tim[f] + 1;
				if(tim[t] > n)
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
//1 A/B > k - T   A - B > log(k-t)   B <= A -log(k-t) - 1 
//2 B/A < k + T   B - A < log(k+t)   B <= A + log(k+t) - 1
bool check(int mid)
{
	for(int i = 1 ; i <= m ; i ++)
	{
		if(in[i].o == 1)
			build(in[i].f,in[i].t,-(log(in[i].d-mid)+1));
		else
			build(in[i].f,in[i].t,log(in[i].d+mid)-1);
	}
	for(int i = 1 ; i <= n ; i ++)
		if(mp[i])
			build(0,i,log(mp[i])) , build(i,0,-log(mp[i]));
		else
			build(0,i,0);
	return spfa(0);
}
int main()
{
	n = read() , m = read() , w = read();
	for(int i = 1 ; i <= n ; i ++)
		l[i].clear() , use[i] = 0 , tim[i] = 0 , mp[i] = 0;
	while(!q.empty())
		q.pop();
	int ll = 214748364 , rr = 0;
	for(int i = 1 ; i <= m ; i ++)
	{
		in[i].o = read() , in[i].f = read() , in[i].t = read() , in[i].d = read();
		rr = max(rr,in[i].d);
		ll = min(ll,in[i].d);
	}
	ll --;
	rr ++;
	for(int i = 1 ; i <= w ; i ++)
	{
		int c = read() , x = read();
		mp[c] = x;
	}
	while(rr - ll > 1)
	{
		int mid = (ll + rr) / 2;
		if(check(mid))
			ll = mid;
		else
			rr = mid;
	}
	printf("%.5lf\n",ll);
	return 0;
}

