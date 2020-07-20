#include<bits/stdc++.h>
#define ll long long
#define lson p*2,l,(l+r)/2
#define rson p*2+1,(l+r)/2+1,r
using namespace std;
const int sz = 1000100;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Tree
{
	int l,r;
	ll sum,mx,se,num;
}tree[sz<<2];
int num[sz];
void pushup(int p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].mx = max(tree[p << 1].mx, tree[p << 1 | 1].mx);
    if (tree[p << 1].mx == tree[p << 1 | 1].mx) {
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
void build_tree(int p, int l, int r) {
    tree[p].l = l , tree[p].r = r;
	if (l == r)
	{
        tree[p].sum = num[l];
        tree[p].mx = tree[p].sum;
        tree[p].se = -1;
        tree[p].num = 1;
        return;
    }
    build_tree(lson);
    build_tree(rson);
    pushup(p);
}
void putTag(int p,int x)
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
void change(int p,int l,int r,int x)
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
int queryMax(int p,int l,int r)
{
    if (l <= tree[p].l && r >= tree[p].r)
	{
        return tree[p].mx;
    }
    pushdown(p);
    int ans = 0;
    int mid = (tree[p].l + tree[p].r) / 2;
    if(l <= mid)
		ans = queryMax(p<<1,l,r);
    if(r > mid)
		ans = max(ans,queryMax(p<<1|1,l,r));
    return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&num[i]);
		build_tree(1,1,n);
		for(int i = 1 ; i <= q ; i ++)
		{
			int op,x,y;
			scanf("%d%d%d",&op,&x,&y);
			if(op == 0)
			{
				int t;
				scanf("%d",&t);
				change(1,x,y,t);
			}
			else if(op == 1)
			{
				printf("%d\n",queryMax(1,x,y));
			}
			else if(op == 2)
			{
				printf("%lld\n",querySum(1,x,y));
			}
		}
	}
	return 0;
}

