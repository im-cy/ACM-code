#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define ll long long
#define lson p*2,l,(l+r)/2
#define rson p*2+1,(l+r)/2+1,r
using namespace std;
const int sz = 200010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
struct node
{
	int t;
	ll d;
};
vector < node > l[sz];
struct Tree
{
	int l,r;
	ll sum,mx,se,num;
}tree[sz<<2];
int rt = 1,cnt,f[sz],d[sz],size[sz],son[sz],rk[sz],top[sz],id[sz];
void pushup(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
    if(tree[p << 1].mx == tree[p << 1 | 1].mx)
	{
        tree[p].se = max(tree[p << 1].se, tree[p << 1 | 1].se);
        tree[p].num = tree[p << 1].num + tree[p << 1 | 1].num;
    }
    else
	{
        //这个地方需要特别注意！因为一个子树的次大值有可能比另一个子树的最大值还要大。所以总的次大值不一定是哪个，需要都比较一下。debug了很久很久。。。
        tree[p].se = max(tree[p<<1].se,tree[p<<1|1].se);
        tree[p].se = max(tree[p].se,min(tree[p << 1].mx, tree[p << 1 | 1].mx));
        tree[p].num = tree[p << 1].mx > tree[p << 1 | 1].mx ? tree[p << 1].num : tree[p << 1 | 1].num;
    }
}
void build_tree(int p, int l, int r)
{
    tree[p].l = l , tree[p].r = r;
	if (l == r)
	{
        tree[p].sum = INF;
        tree[p].mx = tree[p].sum;
        tree[p].se = -1;
        tree[p].num = 1;
        return;
    }
    build_tree(lson);
    build_tree(rson);
    pushup(p);
}
void putTag(int p,ll x)
{
    if(x >= tree[p].mx)
		return;
    tree[p].sum -= tree[p].num * (tree[p].mx - x);
    tree[p].mx = x;
}

void pushdown(int p)
{
    putTag(p<<1,tree[p].mx);
    putTag(p<<1|1,tree[p].mx);
}
void change(int p,int l,int r,ll x)
{
    if(x >= tree[p].mx)
		return;
    if(l <= tree[p].l && r >= tree[p].r && tree[p].se < x)
	{
        putTag(p, x);
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if(l <= mid)
		change(p<<1,l,r,x);
    if(r > mid)
		change(p<<1|1,l,r,x);
    pushup(p);
}
void changep(int p,int l,int r,ll x)
{
    if(l <= tree[p].l && r >= tree[p].r)
	{
        tree[p].sum = x;
        tree[p].mx = tree[p].sum;
        tree[p].se = -1;
        tree[p].num = 1;
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) / 2;
    if(l <= mid)
		change(p<<1,l,r,x);
    if(r > mid)
		change(p<<1|1,l,r,x);
    pushup(p);
}
ll querySum(int p,int l,int r)
{
    if(l <= tree[p].l && r >= tree[p].r)
        return tree[p].sum;
    pushdown(p);
    ll ans = 0;
    int mid = (tree[p].l + tree[p].r) / 2;
    if(l <= mid)
		ans += querySum(p<<1,l,r);
    if(r > mid)
		ans += querySum(p<<1|1,l,r);
    return ans;
}
void dfs1(int u,int fa,int dep)
{
	f[u] = fa;
	d[u] = dep;
	size[u] = 1;
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i].t;
		if(v != fa)
		{
			dfs1(v,u,dep+1);
			size[u] += size[v];
			if(size[v] > size[son[u]])
				son[u] = v;
		}
	}
}
void dfs2(int u,int t)
{
	top[u] = t;
	id[u] = ++ cnt;
	rk[cnt] = u;
	if(!son[u])
		return ;
	dfs2(son[u],t);
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i].t;
		if(v != son[u] && v != f[u])
		{
			dfs2(v,v);
		}
	}
}
ll sum(int x)
{
	ll ans = 0;
	ans += querySum(1,id[x],id[x]);
	return ans;
}
void update(int x,int y,ll c)
{
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]])
			swap(x,y);
		change(1,id[top[x]],id[x],c);
		x = f[top[x]];
	}
	if(id[x] > id[y])
		swap(x,y);
	change(1,id[x],id[y],c);
}
void updatep(int x,ll c)
{
	changep(1,id[x],id[x],c);
}
struct edge
{
	int f,t,id;
	ll d;
	bool pick;
}g[sz],tmp[sz];
ll a[sz],b[sz];
bool cmp(edge a,edge b)
{
	return a.d < b.d;
}
ll dist[sz][32];
int par[sz][32],deep[sz];

void build(int f,int t,ll d)
{
	l[f].push_back({t,d});
	l[t].push_back({f,d});
}
void dfs(int u,int fa,int dep,ll dis)
{
	par[u][0] = fa;
	dist[u][0] = dis;
	deep[u] = dep;
	for(int i = 0 ; i < l[u].size() ; i ++)
	{
		int v = l[u][i].t;
		if(v != fa)
			dfs(v,u,dep+1,l[u][i].d);
	}
}
ll lca_maxdis(int u,int v)
{
	ll ans = 0;
	if(deep[u] < deep[v])
		swap(u,v);
	for(int i = 31 ; i >= 0 ; i --)
		if(deep[par[u][i]] >= deep[v])
			ans = max(dist[u][i],ans) , u = par[u][i];
	for(int i = 31 ; i >= 0 ; i --)
		if(par[u][i] != par[v][i])
			ans = max(dist[u][i],max(dist[v][i],ans)) , u = par[u][i] , v = par[v][i];
	if(u != v)
		ans = max(dist[u][0],max(dist[v][0],ans)) , u = par[u][0] , v = par[v][0];
	return ans;
}
int ask_lca(int u,int v)
{
	if(deep[u] < deep[v])
		swap(u,v);
	for(int i = 31 ; i >= 0 ; i --)
		if(deep[par[u][i]] >= deep[v])
			u = par[u][i];
	for(int i = 31 ; i >= 0 ; i --)
		if(par[u][i] != par[v][i])
			u = par[u][i] , v = par[v][i];
	if(u != v)
		u = par[u][0] , v = par[v][0];
	return u;
}
void init()
{
	for(int i = 1 ; i <= n + 10 ; i ++)
		l[i].clear();
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	memset(f,0,sizeof(f));
	memset(son,0,sizeof(son));
	memset(top,0,sizeof(top));
	memset(id,0,sizeof(id));
	memset(d,0,sizeof(d));
	memset(rk,0,sizeof(rk));
	rt = 1;
	cnt = 0;
}
ll read()
{
	ll x = 0;
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
//	freopen("input.txt","r",stdin);
//	freopen("naive.txt","w",stdout);
	int T = read();
	int cas = 0;
	while(T --)
	{
		n = read() , m = read();
		init();
		for(int i = 1 ; i <= m ; i ++)
		{
			g[i].f = read() , g[i].t = read() , g[i].d = read();
		}
//		sort(g+1,g+m+1,cmp);
		for(int i = 1 ; i < n ; i ++)
			build(g[i].f,g[i].t,g[i].d);
		rt = 1;
		dfs1(rt,0,1);
		dfs2(rt,rt);
		build_tree(1,1,n);
		dfs(1,0,1,0);
		for(int i = 1 ; i <= 31 ; i ++)
			for(int j = 1 ; j <= n ; j ++)
				par[j][i] = par[par[j][i-1]][i-1] , dist[j][i] = max(dist[j][i-1],dist[par[j][i-1]][i-1]);
		for(int i = n ; i <= m ; i ++)
		{
			ll dis = lca_maxdis(g[i].f,g[i].t);
			b[i] = g[i].d - dis;
			int Lca = ask_lca(g[i].f,g[i].t);
			ll temp = sum(Lca);
//			printf("gi %lld\n",temp);
			update(g[i].f,g[i].t,g[i].d);
			updatep(Lca,temp);
		}
		for(int i = 1 ; i < n ; i ++)
		{
			int u = g[i].f , v = g[i].t;
			if(d[u] < d[v])
				swap(u,v);
			ll temp = sum(u);
//			printf("i %d sum %lld\n",i,temp);
			if(temp == INF)
				a[i] = -1;
			else
				a[i] = temp - g[i].d;
		}
		ll ans = 0;
		for(ll i = 1 ; i <= m ; i ++)
		{
//			printf("a %lld b %lld ans %lld\n",a[i],b[i],ans);
			ans += i * a[i] + i * i * b[i];
		}
		printf("Case %d: %lld\n",++cas,ans);
	}
	return 0;
}

