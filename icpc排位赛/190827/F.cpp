#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int sz = 2010;
int n1,n2,m1,m2,Q;
vector < int > l[sz];
void build(int f,int t)
{
	l[f].push_back(t);
}
bool vis[sz][sz];
struct node
{
	int u,d;
};
queue < node > q;
void bfs(int *T,int n)
{
	q.push({1,0});
	vis[1][0] = 1;
	while(!q.empty())
	{
		node f = q.front();
		q.pop();
		if(f.u == n)
		{
			T[f.d] = 1;
			continue;
		}
		for(int i = 0 ; i < l[f.u].size() ; i ++)
		{
			int v = l[f.u][i];
			if(!vis[v][f.d+1])
				q.push({v,f.d+1}) , vis[v][f.d+1] = 1;
		}
	}
}
int T1[sz],T2[sz];
inline bool check(int q)
{
	for(int i = 0 ; i <= q ; i ++)
		if((T1[i] && T2[q-i]) || (T1[q-i] && T2[i]))
			return true;
	return false;
}
inline int read()
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
	n1 = read(),n2 = read(),m1 = read(),m2 = read();
	for(int i = 1 ; i <= m1 ; i ++)
	{
		int f = read(),t = read();
		build(f,t);
	}
	bfs(T1,n1);
	for(int i = 1 ; i <= n1 ; i ++)
		l[i].clear();
	memset(vis,0,sizeof(vis));
	for(int i = 1 ; i <= m2 ; i ++)
	{
		int f = read(),t = read();
		build(f,t);
	}
	bfs(T2,n2);
	Q = read();
	for(int i = 1 ; i <= Q ; i ++)
	{
		int q = read();
		if(check(q))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

