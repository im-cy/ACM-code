#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int sz = 200010;
int head[sz],nxt[sz],l[sz];
int low[sz],dfn[sz],scc_num,dfs_clock;
bool in_stack[sz];
stack < int > s;
struct gtnd
{
    int p,num;
}scc[sz];
int tarjan(int u)
{
    dfn[u] = low[u] = ++ dfs_clock ;
    s.push(u);
    in_stack[u] = 1;
    for(int i = head[u] ; i ; i = nxt[i])
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
        int v;
        do
        {
            v = s.top();
            s.pop();
            in_stack[v] = 0;
			scc[v].num = scc_num;//记录当前点属于第几个scc 
            scc[v].p = v;//记录对应的点 
        }while(u != v)
    }
    return low[u];
}
