#include<iostream>
#include<cstdio>
#include<cstring> 
#define ll long long
using namespace std;
const int size = 200010;
int num[size];
int read()
{
	int x = 0;
	bool flag = 0;
	char ins = getchar();
	while(ins < '0' || ins > '9')
	{
		if(ins == '-')
			flag = 1;
		ins = getchar();
	}
	while(ins >= '0' && ins <= '9')
	{
		x = x * 10 + ins - '0';
		ins = getchar();
	}
	if(flag)
		x = -x;
	return x;
}
struct dc
{
	int l,r;
	ll sum,add;
}tree[size*3];
void build(int p,int l,int r)
{
	tree[p].l = l;
	tree[p].r = r;
	if(l == r)
	{
		tree[p].sum = num[l];
		return ;
	}
	int mid = l + r >> 1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}
void spread(int p)
{
	if(tree[p].add)
	{
		tree[p<<1].sum += tree[p].add * (ll)(tree[p<<1].r - tree[p<<1].l + 1);
		tree[p<<1|1].sum += tree[p].add * (ll)(tree[p<<1|1].r - tree[p<<1|1].l + 1);
		tree[p<<1].add += tree[p].add;
		tree[p<<1|1].add += tree[p].add;
		tree[p].add = 0;
	}
}
void change(int p,int l,int r,int x)
{
	if(l <= tree[p].l && tree[p].r <= r)
	{
		tree[p].sum += (ll)x * (tree[p].r - tree[p].l + 1);
		tree[p].add += x;
		return ;
	}
	spread(p);
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid)
		change(p<<1,l,r,x);
	if(r > mid)
		change(p<<1|1,l,r,x);
	tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}
ll ask(int p,int l,int r)
{
	if(l <= tree[p].l && tree[p].r <= r)
	{
		return tree[p].sum;
	}
	spread(p);
	ll ans = 0;
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid)
		ans += ask(p<<1,l,r);
	if(r > mid)
		ans += ask(p<<1|1,l,r);
	return ans;
}
int n,q;
int main()
{
	n = read() , q = read();
	for(int i = 1 ; i <= n ; i ++)
		num[i] = read();
	build(1,1,n);
	for(int i = 1 ; i <= q ; i ++)
	{
		char ins = getchar();
		while(ins != 'Q' && ins != 'C')
			ins = getchar();
		if(ins == 'Q')
		{
			int l = read() , r = read();
			printf("%lld\n",ask(1,l,r));
		}
		else
		{
			int l = read() , r = read() , x = read();
			change(1,l,r,x);
		}
	}
	return 0;
}
