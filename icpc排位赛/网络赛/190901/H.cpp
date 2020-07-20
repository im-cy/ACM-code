#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 2010;
struct node
{
	int t;
	ll d;
};
vector < node > l[sz];
queue < int > q;
ll read()
{
	ll x = 0 , f = 1;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		if(in == '-')
			f = -1;
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x * f;
}
void build(int f,int t,ll d)
{
	l[f].push_back({t,d});
}
int n,m;
ll dist[sz];
bool use[sz];
void spfa(int s)
{
	for(int i = 1 ; i <= n ; i ++)
		dist[i] = 214748364111111111ll;
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
			ll d = l[f][i].d;
			if(dist[t] > dist[f] + d)
			{
				dist[t] = dist[f] + d;
				if(!use[t])
				{
					use[t] = 1;
					q.push(t);
				}
			}
		}
	}
}
int main()
{
	int T = read();
	while(T --)
	{
		n = read() , m = read();
		for(int i = 1 ; i <= n ; i ++)
			l[i].clear();
		for(int i = 1 ; i <= m ; i ++)
		{
			int f = read() , t = read() , d = read();
			build(f+1,t+1,d);
		}
		for(int i = 1 ; i <= 6 ; i ++)
		{
			int s = read() , e = read();
			s ++;
			e ++;
			spfa(e);
			build(s,e,-dist[s]);
			printf("%lld\n",-dist[s]);
		}
	}
	return 0;
}
/*
1
10 15
4 7 10
7 6 3
5 3 3
1 4 11
0 6 20
9 8 25
3 0 9
1 2 15
9 0 27
5 2 0
7 3 -5
1 7 21
5 0 1
9 3 16
1 8 4
4 1
0 3
6 9
2 1
8 7
0 4
*/

 
