#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int sz = 20010;
struct edge
{
	int t,d;
};
vector < edge > l[sz];
void build(int f,int t,int d)
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
int dist[sz],tim[sz];
queue < int > q;
bool use[sz];
bool spfa(int s)
{
	for(int i = 0 ; i <= n + 5 ; i ++)
		dist[i] = 214748364;
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
			int d = l[f][i].d;
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
int main()
{
	int T = read();
	while(T --)
	{
		n = read() , m = read() , w = read();
		for(int i = 1 ; i <= n ; i ++)
			l[i].clear() , use[i] = 0 , tim[i] = 0;
		while(!q.empty())
			q.pop();
		for(int i = 1 ; i <= m ; i ++)
		{
			int f = read() , t = read() , d = read();
			build(f,t,d);
			build(t,f,d);
		}
		for(int i = 1 ; i <= w ; i ++)
		{
			int f = read() , t = read() , d = read();
			build(f,t,-d);
		}
		for(int i = 1 ; i <= n ; i ++)
			build(0,i,0);
		bool ans = spfa(0);
		if(ans)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}

