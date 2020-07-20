#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int sz = 200010;
int l[sz],hed[sz],nxt[sz];
ll num[sz];
struct Tree
{
	int l,r;
	ll sum,add;
}tree[sz<<2];
int rt = 1,n,m,cnt,f[sz],d[sz],size[sz],son[sz],rk[sz],top[sz],id[sz];
int tot = 1;
ll mod;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void build_tree(int p,int l,int r)
{
	tree[p].l = l , tree[p].r = r;
	if(l == r)
	{
		tree[p].sum = num[rk[l]];
		return ;
	}
	int mid = (l + r) >> 1;
	build_tree(p<<1,l,mid);
	build_tree(p<<1|1,mid+1,r);
	tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}
void spread(int p)
{
	if(tree[p].add)
	{
		tree[p].add %= mod;
		tree[p<<1].add += tree[p].add;
		tree[p<<1|1].add += tree[p].add;
		tree[p<<1].add %= mod;
		tree[p<<1|1].add %= mod;
		tree[p<<1].sum += (tree[p].add * ((tree[p<<1].r - tree[p<<1].l + 1)%mod)) % mod;
		tree[p<<1|1].sum += (tree[p].add * ((tree[p<<1|1].r - tree[p<<1|1].l + 1)%mod)) % mod;
		tree[p<<1].sum %= mod;
		tree[p<<1|1].sum %= mod;
		tree[p].add = 0;
	}
}
void change(int p,int l,int r,ll x)
{
	if(tree[p].l >= l && tree[p].r <= r)
	{
		tree[p].add += x % mod;
		tree[p].sum += ((x%mod) * ((tree[p].r - tree[p].l + 1)%mod)) % mod;
		tree[p].add %= mod;
		tree[p].sum %= mod;
		return ;
	}
	spread(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(mid >= l)
		change(p<<1,l,r,x);
	if(mid < r)
		change(p<<1|1,l,r,x);
	tree[p].sum = (tree[p<<1].sum + tree[p<<1|1].sum) % mod;
}
ll ask(int p,int l,int r)
{
	if(tree[p].l >= l && tree[p].r <= r)
		return tree[p].sum % mod;
	spread(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	ll ans = 0;
	if(mid >= l)
	{
		ans += ask(p<<1,l,r) % mod;
		ans %= mod;
	}
	if(mid < r)
	{
		ans += ask(p<<1|1,l,r) % mod;
		ans %= mod;
	}
	return ans;
}
void dfs1(int u,int fa,int dep)
{
	f[u] = fa;
	d[u] = dep;
	size[u] = 1;
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i];
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
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int v = l[i];
		if(v != son[u] && v != f[u])
		{
			dfs2(v,v);
		}
	}
}
ll sum(int x,int y)
{
	ll ans = 0;
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]])
			swap(x,y);
		ans += ask(1,id[top[x]],id[x]);
		x = f[top[x]];
	}
	if(id[x] > id[y])
		swap(x,y);
	ans += ask(1,id[x],id[y]);
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
int main()
{
	scanf("%d%d%d%lld",&n,&m,&rt,&mod);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%lld",&num[i]) , num[i] %= mod;
	for(int i = 1 ; i < n ; i ++)
	{
		int f,t;
		scanf("%d%d",&f,&t);
		build(f,t);
		build(t,f);
	}
	dfs1(rt,0,1);
	dfs2(rt,rt);
	build_tree(1,1,n);
	for(int i = 1 ; i <= m ; i ++)
	{
		int op,x,y;
		ll z;
		scanf("%d",&op);
		if(op == 1)
		{
			scanf("%d%d%lld",&x,&y,&z);
			update(x,y,z);
		}
		else if(op == 2)
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",sum(x,y)%mod);
		}
		else if(op == 3)
		{
			scanf("%d%lld",&x,&z);
			change(1,id[x],id[x]+size[x]-1,z);
		}
		else if(op == 4)
		{
			scanf("%d",&x);
			printf("%lld\n",ask(1,id[x],id[x]+size[x]-1)%mod);
		}
	}
	return 0;
}


