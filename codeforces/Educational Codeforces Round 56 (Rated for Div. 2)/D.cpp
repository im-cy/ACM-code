#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 500010;
const ll mod = 998244353; 
int hed[sz],nxt[sz],l[sz];
int bw[sz];
int tot = 1;
int n,m;
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}

ll ksm(ll x,ll p)
{
	if(p == 0)
		return 1;
	if(p == 1)
		return x%mod;
	if(p == 2)
		return ((x%mod)*(x%mod))%mod;
	ll temp = ksm(x,p/2) % mod;
	if(p%2)
		return (((temp * temp)%mod) * (x%mod)) % mod;
	return (temp * temp) % mod;
}

bool check()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = hed[i] ; j ; j = nxt[j])
		{
			int t = l[j];
			if(bw[i] == bw[t])
				return false;
		}
	}
	return true;
}

void dfs(int u)
{
	for(int i = hed[u] ; i ; i = nxt[i])
	{
		int t = l[i];
		if(!bw[t])
		{
			bw[t] = -bw[u];
			dfs(t);
		}
	}
}
void init()
{
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(l,0,sizeof(l));
	memset(bw,0,sizeof(bw));
	tot = 1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(f,t);
			build(t,f);
		}
		for(int i = 1 ; i <= n ; i ++)
		{
			if(!bw[i])
			{
				bw[i] = 1;
				dfs(i);
			}
		}
		if(check())
		{
			ll ans = 0;
			int white = 0;
			for(int i = 1 ; i <= n ; i ++)
				if(bw[i] == 1)
					white ++;
			ans += ksm(2,white) % mod;
			ans %= mod;
			ans += ksm(2,n-white) % mod;
			ans %= mod;
			printf("%I64d\n",ans);
		}
		else
		{
			puts("0");
		}
	}
	return 0;
}

