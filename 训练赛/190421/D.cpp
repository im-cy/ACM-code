#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define ll long long
using namespace std;
const int sz = 100001;
int hed[sz],nxt[sz],l[sz],r[sz],c[sz],sccr[sz],sccc[sz];
int low[sz],dfn[sz],scc_num,dfs_clock;
int scc_size[sz];
stack < int > s;
int tot = 1;
struct scc_
{
	int p,num;
}scc[sz];
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int n,m;
int tarjan(int u)
{
	dfn[u] = low[u] = dfs_clock ++;
	s.push(u);
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i];
		if(!dfn[v])
		{
			low[v] = tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(!scc[v].num)
			low[u] = min(low[u],dfn[v]);
	}
	if(low[u] == dfn[u])
	{
		scc_num ++;
		while(12 < 450)
		{
			if(s.empty())
				break;
			int v = s.top();
			s.pop();
			scc[v].num = scc_num;
			scc[v].p = v;
			if(u == v)
				break;
		}
	}
	return low[u];
}
bool check()
{
	for(int i = 1 ; i <= n ; i ++)
	{
//		if(r[i] != c[i])
//			return false;
		scc_size[scc[i].num] ++;
		sccr[scc[i].num] += r[i];
		sccc[scc[i].num] += c[i];
	}
	for(int i = 1 ; i <= scc_num ; i ++)
	{
		if(scc_size[i] == 1)
			return false;
		if(sccr[i] != sccc[i])
			return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		f ++;
		t ++;
		r[t] ++;
		c[f] ++;
		build(f,t);
	}
	for(int i = 1 ; i <= n ; i ++)
		if(!dfn[i])
			tarjan(i);
	if(check())
		puts("YES");
	else
		puts("NO");
	return 0;
}

