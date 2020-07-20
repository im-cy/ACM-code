#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node
{
    int l, r, mid;
    int c;
}a[1000000];
int c[300000];
int num[200010];
int dp[200010];
int ans[200010];
void build(int x, int l, int r)
{
    int mid = (l + r) / 2;
    a[x].l = l;
    a[x].r = r;
    a[x].mid = mid;
    a[x].c = 0;
    if(l == r)
        return ;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid + 1, r);
}

void rejs(int x)
{
    if(a[x].l == a[x].r)
        return ;
    a[x].c = min(a[x * 2].c, a[x * 2 + 1].c);
}

void give(int x, int y, int c)
{
    if(a[x].l != a[x].r)
    {
        if(y <= a[x].mid)
            give(x * 2, y, c);
        else
            give(x * 2 + 1, y, c);
        rejs(x);
    }
    else
        a[x].c = c;
}

void init(int x)
{
    for(int i = 1; i <= x; i ++)
        give(1, i, c[i]);
}


int ask(int x, int l, int r)
{
    //cout << a[x].l << " " << r << endl;
    if(a[x].l == l && a[x].r == r)
        return a[x].c;
    if(r <= a[x].mid)
        return ask(x * 2, l, r);
    if(l > a[x].mid)
        return ask(x * 2 + 1, l, r);
    return min(ask(x * 2, l, a[x].mid), ask(x * 2 + 1, a[x].mid + 1, r));
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	for(int i = 1 ; i <= n - k + 1 ; i ++)
		c[i] = num[i+k-1] - num[i];
	for(int i = n - k + 2 ; i <= n ; i ++)
		c[i] = c[n-k+1];
	build(1, 1, n);
    init(n);
    for(int i = 1 ; i <= n ; i ++)
    	dp[i] = ask(1,max(1,i-k+1),i);
    int ans = 0;
    for(int i = 1 ; i <= n ; i ++)
    	ans = max(dp[i],ans);
    printf("%d\n",ans);
   	return 0;
}

