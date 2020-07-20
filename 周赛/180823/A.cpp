#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int sz = 1001000;
bool use[sz];
bool mp[2600][2600];
int low[sz],dfn[sz],scc_num,dfs_clock;
stack < int > s;
bool ans1,ans2;
struct gtnd
{
    int p,num;
    bool operator <(const gtnd &a)const
    {
        return num < a.num;
    }
}scc[sz];
struct dc
{
	int f,t;
	bool is_p;
}in_data[sz];
void build(int f,int t)
{
	mp[f][t] = 1;
}
int n;
int tarjan(int u)
{
    dfn[u] = low[u] = dfs_clock ++;
    s.push(u);
    for(int i = 1 ; i <= n ; i ++)
    {
    	if(!mp[u][i])
    		continue;
        int v = i;
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
        int scc_size = 0;
        while(12 < 450)
        {
            if(s.empty())
                break;
            int v = s.top();
            s.pop();
            scc[v].num = scc_num;
            scc_size ++;
            scc[v].p = v;
            if(u == v)
                break;
        }
        if(scc_size > 2)
        	ans2 = 1;
    }
    return low[u];
}
void init()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(scc,0,sizeof(scc));
	memset(use,0,sizeof(use));
	memset(mp,0,sizeof(mp));
	scc_num = 0;
	dfs_clock = 0;
	ans1 = ans2 = 0;
	while(!s.empty())
		s.pop();
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		int m = 0;
		init();
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				char ins = getchar();
				while(ins != '-' && ins != 'P' && ins != 'Q')
					ins = getchar();
				if(ins == 'P')
				{
					m ++;
					in_data[m].f = i , in_data[m].t = j , in_data[m].is_p = 1;
				}
				else if(ins == 'Q')
				{
					m ++;
					in_data[m].f = i , in_data[m].t = j , in_data[m].is_p = 0;
				}
			}
		}
		for(int i = 1 ; i <= m ; i ++)
			build(in_data[i].f,in_data[i].t);
		for(int i = 1 ; i <= n ; i ++)	
			if(!dfn[i])
				tarjan(i);
		ans1 = ans2;
		ans2 = 0;
		init();
		for(int i = 1 ; i <= m ; i ++)
		{
			if(in_data[i].is_p)
				build(in_data[i].f,in_data[i].t);
			else
				build(in_data[i].t,in_data[i].f);
		}
		for(int i = 1 ; i <= n ; i ++)	
			if(!dfn[i])
				tarjan(i);
		if(ans1 || ans2)
			puts("N");
		else
			puts("T");
	}
	
	return 0;
}
 
