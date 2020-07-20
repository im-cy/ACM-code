#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll jos_On(ll n,ll m,ll k)// O(m)求n个人走k步第m个出局的玩家 
{
	ll ans = (k-1) % (n-m+1) + 1;
	if(k == 1)
		return m;
	for(int i = 2 ; i <= m ; i ++)
	{
		ans = (ans + k - 1) % (i + n - m) + 1;
	}
	return ans;
}
ll jos_Klogn(ll n,ll m,ll k)//O(klogn)求n个人走k步第m个出局的玩家 
{
	ll ans = (k-1) % (n-m+1) + 1;
	if(k == 1)
		return m;
	ll now = 1 , a = n - m;
	while(now < m)
	{
		ll d = (ll)ceil((now+a-ans)*1.0/(k-1));
		if(d == 0)
			d ++;
		if(now + d >= m)
			d = m - now;
		now += d;
		ll mod = (now + a);
		ans = (ans + k * d % mod - 1 + mod) % mod + 1;
	}
	return ans;
}
inline ll read()
{
	ll x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
		in = getchar();
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
int main()
{
	int T;
	scanf("%d",&T);
	int cas = 0;
	while(T --)
	{
		long long n = read(),m = read(),k = read();
		printf("Case #%d: ",++cas);
		if(m <= k)
			printf("%I64d\n",jos_On(n,m,k));
		else
			printf("%I64d\n",jos_Klogn(n,m,k));
	}
	return 0;
}

