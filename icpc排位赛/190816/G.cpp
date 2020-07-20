#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 2001000;
int f[sz];
int sset[sz];
int find(int x)
{
	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}
struct edge
{
	int f,t;
	ll d;
}l[sz];
bool cmp(edge a,edge b)
{
	return a.d < b.d;
}
int n,m;
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		ll L;
		int S;
		scanf("%d%d%lld%d",&n,&m,&L,&S);
		for(int i = 1 ; i <= n ; i ++)
			f[i] = i;
		for(int i = 1 ; i <= S ; i ++)
		{
			scanf("%d",&sset[i]);
			if(i != 1)
				f[find(sset[i-1])] = find(sset[i]);
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			scanf("%d%d%lld",&l[i].f,&l[i].t,&l[i].d);
		}
		sort(l+1,l+m+1,cmp);
		int tot = 0;
		ll ans = 0;
		for(int i = 1 ; i <= m ; i ++)
		{
			int ff = find(l[i].f);
			int tt = find(l[i].t);
			if(ff != tt)
			{
				ans += l[i].d;
				tot ++;
				f[ff] = tt;
			}
		}
		ans += 1ll * tot * L;
		printf("%lld\n",ans);
	}
	return 0;
}

