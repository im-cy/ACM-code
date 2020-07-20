#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define mod 998244353ll
using namespace std;
ll ny[200010];
ll fact[200010];
ll C(int a,int b)
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
int main()
{
	ll a,b,c;
	cin >> a >> b >> c;
	fact[0] = 1;
	fact[1] = 1;
	ny[0] = 1;
	ny[1] = 1;
	for(int i = 2 ; i <= 5050 ; i ++)
		ny[i] = (ll)((mod - mod/i) * ny[mod%i]) % mod;
	for(int i = 2 ; i <= 5050 ; i ++)
	{
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
		ny[i] = ny[i] * ny[i-1];
		ny[i] %= mod;
	}
	ll ans = 1;
	ans *= f(a,b);
	ans %= mod;
	ans *= f(b,c);
	ans %= mod;
	ans *= f(c,a);
	ans %= mod;
	cout << ans << endl;
	return 0;
}
 
