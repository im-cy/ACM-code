#include<iostream>
#include<cstdio>
#include<cstring>
#define ll int
using namespace std;
const int sz = 50010;
ll num[sz];
int n,m,p;
int f[sz],d[sz],top[sz],id[sz],rk[sz],size[sz],son[sz],cnt;
char ins[11];
int hed[sz],nxt[sz],l[sz];
int tot = 1;
struct Tree
{
	int l,r;
	ll sum,add;
}tree[130000];
void init()
{
	memset(tree,0,sizeof(tree));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(l,0,sizeof(l));
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	memset(top,0,sizeof(top));
	memset(id,0,sizeof(id));
	memset(rk,0,sizeof(rk));
	memset(size,0,sizeof(size));
	memset(son,0,sizeof(son));
	cnt = 0;
	tot = 1;
}
void update(int p)
{
	tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}
void spread(int p)
{
	if(tree[p].add)
	{
		tree[p<<1].add += tree[p].add;
		tree[p<<1|1].add += tree[p].add;
		tree[p<<1].sum += tree[p].add * (tree[p<<1].r - tree[p<<1].l + 1);
		tree[p<<1|1].sum += tree[p].add * (tree[p<<1|1].r - tree[p<<1|1].l + 1);
		tree[p].add = 0;
	}
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
	update(p);
}
void change(int p,int l,int r,int x)
{
	if(tree[p].l >= l && tree[p].r <= r)
	{
		tree[p].add += x;
		tree[p].sum += x * (tree[p].r - tree[p].l + 1);
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
	while(scanf("%d%d%d",&n,&m,&p) != EOF)
	{
		init();
		for(int i = 1 ; i <= n ; i ++)
			num[i] = read();
		for(int i = 1 ; i < n ; i ++)
		{
			int f,t;
			f = read() , t = read();
			build(f,t) , build(t,f);
		}
		dfs1(1,0,1);
		dfs2(1,1);
		build_tree(1,1,n);
		for(int i = 1 ; i <= p ; i ++)
		{
			int u,v,k;
			scanf("%s",ins);
			if(ins[0] == 'I')
			{
				u = read() , v = read() , k = read();
				changes(u,v,k);
			}
			else if(ins[0] == 'D')
			{
				u = read() , v = read() , k = read();
				changes(u,v,-k);
			}
			else
			{
				u = read();
				printf("%d\n",sum(u,u));
			}
		}
	}
	return 0;
} 
