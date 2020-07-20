#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define ll long long
#define mod 1000000007
#define eps 1e-12
#define maxn 50010
ll read()
{
    ll x=0; char c=getchar(),f=1;
    for(;c<'0'||'9'<c;c=getchar())if(c=='-')f=-1;
    for(;'0'<=c&&c<='9';c=getchar())x=x*10+c-'0';
    return x*f;
}
inline void write(ll x)
{
    static int buf[20] ,len;
	len = 0;
    if(x < 0)
		x = -x , putchar('-');
    for( ; x ; x /= 10)
		buf[len++] = x % 10;
    if(!len)
		putchar('0');
    else
		while(len)
			putchar(buf[--len] + '0');
}
void writeln(ll x){write(x); putchar('\n');}
struct line
{
    double k,b;
    int l,r;
}sgt[4*maxn];
int n;
char op[10];
double calc(line a,int pos)
{
	return a.k*pos+a.b;
}
int cross(line a,line b)
{
	return floor((a.b-b.b)/(b.k-a.k));
}
void build(int now,int l,int r)
{
    sgt[now].k = sgt[now].b = 0;
	sgt[now].l = 1;
	sgt[now].r = 50000;
    if(l == r)
		return;
    int mid = (l + r) >> 1;
    build(now<<1,l,mid);
	build(now<<1|1,mid+1,r);
}
void modify(int now,int l,int r,line k)
{
    if(k.l <= l && r <= k.r)
	{
        if(calc(k,l) - calc(sgt[now],l) > eps && calc(k,r) - calc(sgt[now],r) > eps)
			sgt[now] = k;
        else if(calc(k,l) - calc(sgt[now],l) > eps || calc(k,r) - calc(sgt[now],r) > eps)
		{
            int mid = (l + r) >> 1;
            if(calc(k,mid) - calc(sgt[now],mid) > eps)
			{
                line tmp = k;
				k = sgt[now];
				sgt[now] = tmp;
            }
            if(cross(k,sgt[now]) - mid < -eps)
				modify(now<<1,l,mid,k);
            else
				modify(now<<1|1,mid+1,r,k);
        }
    }
    else
	{
        int mid = (l + r) >> 1;
        if(k.l <= mid)
			modify(now<<1,l,mid,k);
        if(mid < k.r)
			modify(now<<1|1,mid+1,r,k);
    }
}
double query(int now,int l,int r,int x)
{
    if(l == r)
		return calc(sgt[now],x);
    else
	{
        int mid = (l + r) >> 1;
        double ans = calc(sgt[now],x);
        if(x <= mid)
			return std::max(ans,query(now<<1,l,mid,x));
        else
			return std::max(ans,query(now<<1|1,mid+1,r,x));
    }
}
int main()
{
    n = read();
    build(1,1,50000);
    for(int i = 1 ; i <= n ; i ++)
	{
        scanf("%s",op);
        if(op[0] == 'P')
		{
            double s,p;
            scanf("%lf%lf",&s,&p);
            line now;
			now.l = 1;
			now.r = 50000;
			now.k = p;
			now.b = s - p;
            modify(1,1,50000,now);
        }
        else
		{
			int x = read();
			printf("%lld\n",(ll)floor(query(1,1,50000,x)/100));
        }
    }
    return 0;
}
