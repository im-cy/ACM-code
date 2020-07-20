#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int size = 200010;
stack < int > s;
int l[size],head[size],next[size];
int tot = 1;
void build(int f,int t)
{
	l[tot] = t;
	next[tot] = head[f];
	head[f] = tot ++;
}
int n,m;
int dfs_clock,low[size],dfn[size],scc[size],scc_num;
int tarjan(int u)
{
	low[u] = dfn[u] = ++ dfs_clock;
	s.push(u);
	for(int i = head[u] ; i ; i = next[i])
	{
		int v = l[i];
		if(!dfn[v])
		{
			low[v] = tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(!scc[v])
		{
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(dfn[u] == low[u])
	{
		scc_num ++;
		while(12 < 450)
		{
			int f = s.top();
			s.pop();
			scc[f] = scc_num;
			if(f == u)
				break;
		}	
	}
	return low[u];
}
int c[size];
void init()
{
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(l,0,sizeof(l));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	while(!s.empty())
		s.pop();
	tot = 1;
	dfs_clock = 0;
	scc_num = 0;
	
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		init();
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(f,t);
		}
		for(int i = 1 ; i <= n ; i ++)
			if(!dfn[i])
				tarjan(i);
		int newm = 0;
		int pos = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = head[i] ; j ; j = next[j])
			{
				int t = l[j];
				if(scc[i] != scc[t])
					c[scc[i]] ++;
			}
		}
		int ans = 0;
		for(int i = 1 ; i <= scc_num ; i ++)
			if(c[i] == 0)
			{
				pos = i;
				newm ++;
			}
		if(newm == 1)
		{
			for(int i = 1 ; i <= n ; i ++)
				if(scc[i] == pos)
					ans ++;
			printf("%d\n",ans);
		}
		else
			puts("0");
	}
	return 0;
}
