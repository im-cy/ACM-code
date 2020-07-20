#include <bits/stdc++.h>
using namespace std;
const int sz = 100005;
int l[sz*50];
int hed[sz*50];
int nxt[sz*50];
int tot = 1;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int num[sz][50];// n day -> num
struct node
{
	int u,day;
}renum[sz*50];//num -> n day
int dp[sz*50];
//bool op[sz][50];
bitset<55> op[sz];
bool use[sz];
int dis[sz*50];
//bool vis[sz*50];
//int rd[sz*50];
char tmp[51];
int cnt;
int n,m,d;
int low[sz*50],dfn[sz*50],scc_num,dfs_clock;
bool in_stack[sz*50];
stack < int > s;
struct gtnd
{
    int p,num;
}scc[sz*50];
struct edge
{
	int f,t;
	bool operator < (const edge &a)const
	{
		if(f == a.f)
			return t < a.t;
		return f < a.f;
	}
	bool operator ==(const edge &a)const
	{
		if(f == a.f && t == a.t)
			return true;
		return false;
	}
};
vector <edge> g;
int temp[sz];
inline int tarjan(int u)
{
    dfn[u] = low[u] = ++ dfs_clock ;
    s.push(u);
    in_stack[u] = 1;
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
        int v;
        int tl = 0;
        do
        {
            v = s.top();
            s.pop();
            in_stack[v] = 0;
			scc[v].num = scc_num;//记录当前点属于第几个scc 
            scc[v].p = v;//记录对应的点 
            if(op[renum[v].u][renum[v].day] && !use[renum[v].u])
            {
            	dis[scc_num] ++;
            	use[renum[v].u] = 1;
            	temp[++tl] = renum[v].u;
            }
        }while(u != v);
        for(int i = 1 ; i <= tl ; i ++)
        	use[temp[i]] = 0;
    }
    return low[u];
}
int read()
{
	int x = 0 , f = 1;
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
	return x * f;
}
int main()
{
	n = read() , m = read() , d = read();
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j < d ; j ++)
		{
			num[i][j] = ++ cnt;
			renum[cnt].u = i;
			renum[cnt].day = j;
		}
    for(int i = 1 ; i <= m ; i ++)
    {
    	int f = read(),t = read();
    	for(int j = 0 ; j < d ; j ++)
    	{
    		build(num[f][j],num[t][(j+1)%d]);
    	}
    }
    for(int i = 1 ; i <= n ; i ++)
    {
    	scanf("%s",tmp);
    	for(int j = 0 ; j < d ; j ++)
    	{
    		if(tmp[j] == '1')
    			op[i][j] = 1;
    	}
    }
    for(int i = 1 ; i <= cnt ; i ++)
    	if(!dfn[i])
    		tarjan(i);
//    printf("sccnum %d\n",scc_num);	
    for(int i = 1 ; i <= cnt ; i ++)
    {
    	for(int j = hed[i] ; j ; j = nxt[j])
    	{
    		int f = i , t = l[j];
    		if(scc[f].num != scc[t].num)
    		{
    			edge nxt;
    			nxt.f = scc[f].num;
    			nxt.t = scc[t].num;
    			g.push_back(nxt);
    		}
    	}
    }
    memset(hed,0,sizeof(hed));
    tot = 1;
    sort(g.begin(),g.end());
    g.erase(unique(g.begin(),g.end()),g.end());
    for(int i = 0 ; i < g.size() ; i ++)
    {
    	build(g[i].f,g[i].t);
    }
    for(int i = 1 ; i <= scc_num ; i ++)
    {
    	int f = i;
    	for(int j = hed[f] ; j ; j = nxt[j])
    	{
    		int t = l[j];
    		dp[f] = max(dp[f],dp[t]);
    	}
    	dp[f] += dis[f];
    }
    printf("%d\n",dp[scc[1].num]);
    return 0;
}
/*
5 5 10
1 2
2 3
3 4
4 5
5 4
0000000000
0000000000
0000000000
0001000000
0000001010
*/
