#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
struct Tree
{
	int ls,rs,sum;
}tree[sz<<5];
int num[sz],san[sz],T[sz];
int n,m,tot=0;

void build(int l,int r,int &x)
{
	x = ++ tot;
	tree[x].sum = 0;
	if(l == r)
		return ;
	int mid = (l+r)/2;
	build(l,mid,tree[x].ls);
	build(mid+1,r,tree[x].rs);
}
void update(int last,int p,int l,int r,int &x)
{
	x = ++ tot;
	tree[x] = tree[last];
	tree[x].sum ++;
	if(l == r)
		return ;
	int mid = (l + r) / 2;
	if(p <= mid)
		update(tree[last].ls,p,l,mid,tree[x].ls);
	else
		update(tree[last].rs,p,mid+1,r,tree[x].rs);
}
int query(int s,int t,int l,int r,int k)
{
	if(l == r)
		return l;
	int mid = (l + r) / 2;
	int cnt = tree[tree[t].ls].sum - tree[tree[s].ls].sum;
	if(k <= cnt)
		return query(tree[s].ls,tree[t].ls,l,mid,k);
	return query(tree[s].rs,tree[t].rs,mid+1,r,k-cnt);
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
	n = read() , m = read();
	for(int i = 1 ; i <= n ; i ++)
	{
		san[i] = read();
		num[i] = san[i];
	}
	sort(san+1,san+n+1);
	int cnt = unique(san+1,san+n+1) - san - 1;
	build(1,cnt,T[0]);
	for(int i = 1 ; i <= n ; i ++)
		num[i] = lower_bound(san+1,san+cnt+1,num[i]) - san;
	for(int i = 1 ; i <= n ; i ++)
		update(T[i-1],num[i],1,cnt,T[i]);
	for(int i = 1 ; i <= m ; i ++)
	{
		int l = read() , r = read() , k = read();
		printf("%d\n",san[query(T[l-1],T[r],1,cnt,k)]);
	}
	return 0;
}

