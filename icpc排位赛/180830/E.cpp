#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll ksm(ll x,ll p,ll mod)
{
	if(p == 0)
		return 1;
	if(p == 1)
		return x % mod;
	if(p == 2)
		return ((x % mod) * (x % mod)) % mod;
	ll temp = ksm(x,p/2,mod) % mod;
	if(p % 2 == 1)
		return (((temp * temp) % mod) * (x % mod)) % mod;
	if(p % 2 != 1)
		return (temp * temp) % mod;
}
ll n,mod,k;
int main()
{
	scanf("%lld%lld%lld",&n,&k,&mod);
	ll temp = (ksm(2,n,mod-1)- (n%(mod-1)) + mod - 1 ) % (mod-1);
	temp += 2*(mod - 1);
	ll ans = ksm(2,temp,mod);
	if(k == 0)
		ans --;
	ans += mod;
	cout << ans % mod << endl;
	return 0;
}
 
