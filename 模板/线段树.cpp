#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 200010;
struct xd_tree
{
    int l,r;
    ll sum,min,max,add;
}tree[sz*4];
int num[sz];
int n;
void updata(int p)
{
    tree[p].min = min(tree[p<<1].min,tree[p<<1|1].min);
    tree[p].max = max(tree[p<<1].max,tree[p<<1|1].max);
    tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}
void build_tree(int p,int l,int r)
{
    tree[p].l = l , tree[p].r = r;
    if(l == r)
    {
        tree[p].min = tree[p].max = tree[p].sum = num[l];
        return ;
    }
    int mid = l + r >> 1;
    build_tree(p<<1,l,mid);
    build_tree(p<<1|1,mid+1,r);
    updata(p);
}
void spread(int p)
{
    if(tree[p].add)
    {
        tree[p<<1].sum += tree[p].add * (tree[p<<1].r - tree[p<<1].l + 1);
        tree[p<<1|1].sum += tree[p].add * (tree[p<<1|1].r - tree[p<<1|1].l + 1);
        tree[p<<1].min += tree[p].add;
        tree[p<<1|1].min += tree[p].add;
        tree[p<<1].max += tree[p].add;
        tree[p<<1|1].max += tree[p].add;
        tree[p<<1].add += tree[p].add;
        tree[p<<1|1].add += tree[p].add;
        tree[p].add = 0;
    }
    return ;
}
void change(int p,int l,int r,int x)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        tree[p].sum += x * (tree[p].r - tree[p].l + 1);
        tree[p].max += x;
        tree[p].min += x;
        tree[p].add += x;
        return ;
    }
    spread(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid)
        change(p<<1,l,r,x);
    if(r > mid)
        change(p<<1|1,l,r,x);
    updata(p);
}
ll ask_sum(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].sum;
    spread(p);
    int mid = tree[p].l + tree[p].r >> 1;
    ll ans = 0;
    if(l <= mid)
        ans += ask_sum(p<<1,l,r);
    if(r > mid)
        ans += ask_sum(p<<1|1,l,r);
    return ans; 
}
ll ask_min(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].min;
    spread(p);
    int mid = tree[p].l + tree[p].r >> 1;
    ll ans = 214748364111111ll;
    if(l <= mid)
        ans = min(ask_min(p<<1,l,r),ans);
    if(r > mid)
        ans = min(ask_min(p<<1|1,l,r),ans);
    return ans;
}
ll ask_max(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].max;
    spread(p);
    int mid = tree[p].l + tree[p].r >> 1;
    ll ans = 0;
    if(l <= mid)
        ans = max(ask_max(p<<1,l,r),ans);
    if(r > mid)
        ans = max(ask_max(p<<1|1,l,r),ans);
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++)
        scanf("%d",&num[i]);
    build_tree(1,1,n);
    return 0;
}
