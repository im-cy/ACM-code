#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int sz = 20010;
int hed[sz],nxt[sz],l[sz];
int nhed[sz],nnxt[sz],nl[sz];
int low[sz],dfn[sz],scc_num,dfs_clock;
int rd[sz];
bool in_stack[sz],use[1010][1010];
stack < int > s;
queue < int > q;
struct gtnd
{
    int p,num;
}scc[sz];
int tot = 1,ntot = 1;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void nbuild(int f,int t)
{
	nl[ntot] = t;
	nnxt[ntot] = nhed[f];
	nhed[f] = ntot ++;
}
void init()
{
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(l,0,sizeof(l));
	memset(nhed,0,sizeof(nhed));
	memset(nnxt,0,sizeof(nnxt));
	memset(nl,0,sizeof(nl));
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(rd,0,sizeof(rd));
	memset(scc,0,sizeof(scc));
	memset(use,0,sizeof(use));
	memset(in_stack,0,sizeof(in_stack));
	tot = 1;
	ntot = 1;
	scc_num = dfs_clock = 0;
	while(!s.empty())
		s.pop();
	while(!q.empty())
		q.pop();
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++ dfs_clock;
    s.push(u);
    in_stack[u] = 1;
    for(int i = hed[u] ; i ; i = nxt[i])
    {
        int v = l[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(in_stack[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(low[u] == dfn[u])
    {
        scc_num ++;
        int v;
        do
        {
            v = s.top();
            s.pop();
            in_stack[v] = 0;
            scc[v].num = scc_num;//记录当前点属于第几个scc 
            scc[v].p = v;//记录对应的点 
        }while(u != v);
    }
}
bool topsort()
{
	int cnt = 0;
	for(int i = 1 ; i <= scc_num ; i ++)
		if(!rd[i])
		{
			cnt ++;
			q.push(i);
		}
	if(cnt > 1)
		return false;
	while(!q.empty())
	{
		cnt = 0;
		int f = q.front();
		q.pop();
//		printf("f %d\n",f);
		for(int i = nhed[f] ; i ; i = nnxt[i])
		{
			int t = nl[i];
			rd[t] --;
			if(rd[t] <= 0)
			{
				cnt ++;
				q.push(t);
			}
		}
//		printf("cnt %d\n",cnt);
		if(cnt > 1)
			return false;
		cnt = 0;
	}
	return true;
}
int main()
{
	int n,m;
	int T;
	scanf("%d",&T);
	while(T --)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(f,t);
		}
		for(int i = 1 ; i <= n ; i ++)
			if(!dfn[i])
				tarjan(i);
//		printf("%d\n",scc_num);
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = hed[i] ; j ; j = nxt[j])
			{
				int t = l[j];
				if(scc[i].num != scc[t].num && !use[scc[i].num][scc[t].num])
				{
					nbuild(scc[i].num,scc[t].num);
//					printf("build %d to %d\n",scc[i].num,scc[t].num);
					use[scc[i].num][scc[t].num] = 1;
					rd[scc[t].num] ++;
//					puts("wwww");
				}
			}
		}
		bool ans = topsort();
		if(ans)
			puts("Yes");
		else
			puts("No");
	}
}
