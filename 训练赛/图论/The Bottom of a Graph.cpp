#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz],l[sz];
int low[sz],dfn[sz],scc_num,dfs_clock;
int cd[sz];
bool T[sz];
stack < int > s;
struct gtnd
{
    int p,num;
}scc[sz];
int tot = 1;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void init()
{
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(l,0,sizeof(l));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(cd,0,sizeof(cd));
	memset(T,0,sizeof(T));
	memset(scc,0,sizeof(scc));
	tot = 1;
	scc_num = dfs_clock = 0;
	while(!s.empty())
		s.pop();
	
}
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
            scc[v].num = scc_num;//记录当前点属于第几个scc 
            scc[v].p = v;//记录对应的点 
            if(u == v)
                break;
        }
    }
    return low[u];
}
int main()
{
	int n,m;
	while(scanf("%d",&n) && n)
	{
		init();
		scanf("%d",&m);
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(f,t);
		}
		for(int i = 1 ; i <= n ; i ++)
			if(!dfn[i])
				tarjan(i);
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = hed[i] ; j ; j = nxt[j])
			{
				int t = l[j];
				if(scc[i].num != scc[t].num)
				{
					cd[scc[i].num] ++;
				}
			}
			if(cd[scc[i].num])
				T[scc[i].num] = 1;
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			if(!T[scc[i].num])
				printf("%d ",i);
		}
		puts("");
	}
}
