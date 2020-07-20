#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
const ll mod = 1e9 + 7;
int l[201010],r[201010];
ll ny[201010];
ll fact[201010];
char s[201010];
ll C(ll a,ll b)
{
	return (((fact[a] * ny[b])%mod) * ny[a-b])%mod;
}
ll f(ll a,ll b)
{
	ll ans = 0;
	ll n = min(a,b);
	for(int i = 0 ; i <= n ; i ++)
	{
		ans += (((C(a,i) * C(b,i))%mod) * fact[i]) % mod;
		ans %= mod;
	}
	return ans;
}
void init()
{
	fact[0] = 1;
	fact[1] = 1;
	ny[0] = 1;
	ny[1] = 1;
	for(int i = 2 ; i <= 2e5+50 ; i ++)
		ny[i] = (ll)((mod - mod/i) * ny[mod%i]) % mod;
	for(int i = 2 ; i <= 2e5+50 ; i ++)
	{
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
		ny[i] = ny[i] * ny[i-1];
		ny[i] %= mod;
	}
}
int main()
{
	fact[0] = 1;
	fact[1] = 1;
	ny[0] = 1;
	ny[1] = 1;
	for(int i = 2 ; i <= 200000+50 ; i ++)
		ny[i] = (ll)((mod - mod/i) * ny[mod%i]) % mod;
	for(int i = 2 ; i <= 200000+50 ; i ++)
	{
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
		ny[i] = ny[i] * ny[i-1];
		ny[i] %= mod;
	}
	scanf("%s",s+1);
	n = strlen(s+1);
	for(int i = 1 ; i <= n ; i ++)
	{
		if(s[i] == '(')
			l[i] = l[i-1] + 1;
		else
			l[i] = l[i-1];
	}
	for(int i = n ; i >= 1 ; i --)
	{
		if(s[i] == ')')
			r[i] = r[i+1] + 1;
		else
			r[i] = r[i+1];
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(s[i] == '(')
		{
			ans += C(l[i]-1+r[i],l[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
 
