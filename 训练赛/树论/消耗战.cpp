#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 250011;
ll inf;
int n,m,ecnt,tot,id[sz],k;
struct edge
{
    int t,d;
};
vector < edge > l[sz];
int hed[sz],nxt[sz],edge[sz];
ll val[sz];
int pre[sz][19],deep[sz];
int que[sz],top,Stack[sz];
ll f[sz];
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
ll min(ll x,ll y)
{
	if(x < y)
		return x;
	return y;
}
void dfs(int u,int fa)
{
    pre[u][0] = fa;
	id[u] = ++ ecnt;
    for(int i = 1 ; i <= 18 ; i ++)
		pre[u][i] = pre[pre[u][i-1]][i-1];
    for(int i = 0 ; i < l[u].size() ; i ++)
	{
	    int v = l[u][i].t;
	    int w = l[u][i].d;
	    if(v == fa)
			continue;
	    val[v] = min(w,val[u]);
		deep[v] = deep[u] + 1;
	    dfs(v,u);
    }
}
bool cmp(int a,int b)
{
	return id[a] < id[b];
}
int lca(int x,int y)
{
    if(deep[x] < deep[y])
		swap(x,y);
    int t = 0;
	while((1<<t) <= deep[x])
		t ++;
    t--;
	for(int i = t ; i >= 0 ; i --)
		if(deep[x]-(1<<i) >= deep[y])
			x = pre[x][i];
    if(x == y)
		return y;
    for(int i = t ; i >= 0 ; i --)
		if(pre[x][i] != pre[y][i])
		{
			x = pre[x][i];
			y = pre[y][i];
		} 
    return pre[x][0];
}
void build(int f,int t)
{
	if(f == t)
		return ;
	nxt[++ecnt] = hed[f];
	hed[f] = ecnt;
	edge[ecnt] = t;
}

void dp(int u)
{
    ll lin = 0;
	f[u] = val[u];
	printf("%d %d\n",u,hed[u]);
    for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = edge[i];
    	dp(v);
    	lin += f[v];
    }
    hed[u] = 0;
    if(!lin)
		f[u] = val[u];
    else if(lin < f[u])
		f[u] = lin;
}

void build_vtree()
{
    m = read();
	for(int i = 1 ; i <= m ; i ++)
		que[i] = read();
    sort(que+1,que+m+1,cmp);
    tot = 0;
	que[++tot] = que[1]; 
    for(int i = 2 ; i <= m ; i ++)
		if(lca(que[i],que[tot]) != que[tot])
			que[++tot] = que[i];
    top = 0;
	Stack[++top] = 1;
	int grand;
    ecnt = 0;
    for(int i = 1 ; i <= tot ; i ++)
	{
    	grand = lca(Stack[top],que[i]);
    	while(1)
		{
       		if(deep[Stack[top-1]] <= deep[grand])
			{
        		build(grand,Stack[top]);
				top--;
        		if(Stack[top] != grand)
					Stack[++top] = grand;
        		break;
        	}
        	build(Stack[top-1],Stack[top]);
			top --;
    	}
		if(Stack[top] != que[i])
			Stack[++top] = que[i];
    }
    top --;
    while(top)
		build(Stack[top],Stack[top+1]) , top --;
}
void solve()
{
	dp(1);
    printf("%lld\n",f[1]);
}

int main()
{
	n = read();
    inf = 1;
	for(int i = 1 ; i <= 60 ; i ++)
		inf *= 2;
    for(int i = 1 ; i < n ; i ++)
	{
    	int f = read() , t = read() , d = read();
		l[f].push_back({t,d});
		l[t].push_back({f,d});
    }
    val[1] = inf;
	ecnt = 0;
	deep[1] = 0;
	dfs(1,0);
    k = read();
	for(int i = 1 ; i <= k ; i ++)
		build_vtree() , solve();
	return 0;
}
