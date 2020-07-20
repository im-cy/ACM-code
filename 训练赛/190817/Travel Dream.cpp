#include<bits/stdc++.h>
using namespace std;
const int sz = 2010;
struct node
{
	int t,d;
};
vector < node > l[sz];
void build(int f,int t,int d)
{
	l[f].push_back({t,d});
	l[t].push_back({f,d});
}
int n,m,k;
int ans = 0;
bool vis[sz];
void dfs(int u,int dep,int dis,int root)
{
	if(dep > k)
		return ;
	vis[u] = 1;
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i].t;
		int w = l[u][i].d;
		if(dep == k && v == root)
		{
			ans = max(ans,dis+w);
		}
		if(vis[v])
			continue;
		dfs(v,dep+1,dis+w,root);
		vis[v] = 0;
	}
	return ;
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
	n = read() , m = read() , k = read();
	for(int i = 1 ; i <= m ; i ++)
	{
		int f = read(),t = read(),d = read();
		build(f,t,d);
	}
	for(int i = 1 ; i <= n ; i ++)
		dfs(i,1,0,i);
	if(!ans)
		puts("impossible");
	else
		printf("%d\n",ans);
	return 0;
}


