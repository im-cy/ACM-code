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
	int cnt = tree[t].sum - tree[s].sum;
	if(r <= k)
		return cnt;
	if(l > k)
		return 0;
	int mid = (l + r) / 2;
	int ans = 0;
	if(k <= mid)
		ans += query(tree[s].ls,tree[t].ls,l,mid,k);
	if(k > mid)
		ans += query(tree[s].rs,tree[t].rs,mid+1,r,k) + query(tree[s].ls,tree[t].ls,l,mid,k);
	return ans;
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
struct Q
{
	int l,r,x;
}qes[sz];
int main()
{
	int K;
	scanf("%d",&K);
	int k = 1; 
	while(K --) 
	{
		tot = 0;
		n = read() , m = read();
		for(int i = 1 ; i <= n ; i ++)
		{
			san[i] = read();
			num[i] = san[i];
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			qes[i].l = read() + 1 , qes[i].r = read() + 1 , qes[i].x = read();
			san[n+i] = qes[i].x;
		}
		sort(san+1,san+n+m+1);
		int cnt = unique(san+1,san+n+m+1) - san - 1;
		build(1,cnt,T[0]);
		for(int i = 1 ; i <= n ; i ++)
			num[i] = lower_bound(san+1,san+cnt+1,num[i]) - san;
		for(int i = 1 ; i <= m ; i ++)
			qes[i].x = lower_bound(san+1,san+cnt+1,qes[i].x) - san;
		for(int i = 1 ; i <= n ; i ++)
			update(T[i-1],num[i],1,cnt,T[i]);
		printf("Case %d:\n",k ++);
		for(int i = 1 ; i <= m ; i ++)
		{
			printf("%d\n",query(T[qes[i].l-1],T[qes[i].r],1,cnt,qes[i].x));
		}
	}
	return 0;
}

