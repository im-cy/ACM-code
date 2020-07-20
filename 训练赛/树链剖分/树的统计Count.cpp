#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int sz = 200010;
ll num[sz];
int n,m;
int f[sz],d[sz],top[sz],id[sz],rk[sz],size[sz],son[sz],cnt;
char ins[11];
struct Tree
{
	int l,r;
	ll sum,max,add;
}tree[sz<<2];
void update(int p)
{
	tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
	tree[p].max = max(tree[p<<1].max,tree[p<<1|1].max);
}
void spread(int p)
{
	if(tree[p].add)
	{
		tree[p<<1].add += tree[p].add;
		tree[p<<1|1].add += tree[p].add;
		tree[p<<1].sum += tree[p].add * (tree[p<<1].r - tree[p<<1].l + 1);
		tree[p<<1|1].sum += tree[p].add * (tree[p<<1|1].r - tree[p<<1|1].l + 1);
		tree[p<<1].max += tree[p].add;
		tree[p<<1|1].max += tree[p].add;
		tree[p].add = 0;
	}
}
void build_tree(int p,int l,int r)
{
	tree[p].l = l , tree[p].r = r;
	if(l == r)
	{
		tree[p].sum = tree[p].max = num[rk[l]];
		return ;
	}
	int mid = (l + r) >> 1;
	build_tree(p<<1,l,mid);
	build_tree(p<<1|1,mid+1,r);
	update(p);
}
void change(int p,int l,int r,int x)
{
	if(tree[p].l >= l && tree[p].r <= r)
	{
		tree[p].add += x;
		tree[p].sum += x * (tree[p].r - tree[p].l + 1);
		tree[p].max += x;
		return ;
	}
	spread(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(mid >= l)
		change(p<<1,l,r,x);
	if(mid < r)
		change(p<<1|1,l,r,x);
	update(p);
}
ll ask_sum(int p,int l,int r)
{
	if(tree[p].l >= l && tree[p].r <= r)
		return tree[p].sum;
	spread(p);
	ll ans = 0;
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(mid >= l)
		ans += ask_sum(p<<1,l,r);
	if(mid < r)
		ans += ask_sum(p<<1|1,l,r);
	return ans;
}
ll ask_max(int p,int l,int r)
{
	if(tree[p].l >= l && tree[p].r <= r)
		return tree[p].max;
	spread(p);
	ll ans = -2147483641;
	int mid = (tree[p].l + tree[p].r) >> 1;
	if(mid >= l)
		ans = max(ask_max(p<<1,l,r),ans);
	if(mid < r)
		ans = max(ask_max(p<<1|1,l,r),ans);
	return ans;
}
int hed[sz],nxt[sz],l[sz];
int tot = 1;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void dfs1(int u,int fa,int dep)
{
	d[u] = dep;
	f[u] = fa;
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
		if(v != f[u] && v != son[u])
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
		ans += ask_sum(1,id[top[x]],id[x]);
		x = f[top[x]];
	}
	if(id[x] > id[y])
		swap(x,y);
	ans += ask_sum(1,id[x],id[y]);
	return ans;
}
ll maxs(int x,int y)
{
	ll ans = -2147483641;
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]])
			swap(x,y);
		ans = max(ask_max(1,id[top[x]],id[x]),ans);
		x = f[top[x]];
	}
	if(id[x] > id[y])
		swap(x,y);
	ans = max(ask_max(1,id[x],id[y]),ans);
	return ans;
}
void changes(int x,int y,ll z)
{
	while(top[x] != top[y])
	{
		if(d[top[x]] < d[top[y]])
			swap(x,y);
		change(1,id[top[x]],id[x],z);
		x = f[top[x]];
	}
	if(id[x] > id[y])
		swap(x,y);
	change(1,id[x],id[y],z);
}
int read()
{
	int x = 0 , f = 1;
	char ins = getchar();
	while(ins < '0' || ins > '9')
	{
		if(ins == '-')
			f = -1;
		ins = getchar();
	}
	while(ins >= '0' && ins <= '9')
	{
		x = (x << 3) + (x << 1) + ins - '0';
		ins = getchar();
	}
	return x * f;
}
int main()
{
	n = read();
	for(int i = 1 ; i < n ; i ++)
	{
		int f,t;
		f = read() , t = read();
		build(f,t) , build(t,f);
	}
	for(int i = 1 ; i <= n ; i ++)
		num[i] = read();
	dfs1(1,0,1);
	dfs2(1,1);
	build_tree(1,1,n);
	m = read();
	for(int i = 1 ; i <= m ; i ++)
	{
		int u,v;
		scanf("%s",ins);
		u = read() , v = read();
		if(ins[0] == 'C')
		{//点修改 
			ll temp = sum(u,u);
			changes(u,u,-temp);
			changes(u,u,v);
		}
		else if(ins[1] == 'M')
		{//区间最大 
			printf("%lld\n",maxs(u,v));
		}
		else
		{//区间求和 
			printf("%lld\n",sum(u,v));
		}
	}
	return 0;
} 
